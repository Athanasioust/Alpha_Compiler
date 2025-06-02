#include "avm.h"

// Hash function for strings
static unsigned avm_hash_string(char* str) {
    unsigned hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % AVM_TABLE_HASHSIZE;
}

// Hash function for numbers
static unsigned avm_hash_number(double num) {
    return ((unsigned)(num * 2654435761U)) % AVM_TABLE_HASHSIZE;
}

// Hash function for functions
static unsigned avm_hash_func(unsigned funcVal) {
    return (funcVal * 2654435761U) % AVM_TABLE_HASHSIZE;
}

// Create new table
avm_table* avm_tablenew(void) {
    avm_table* t = (avm_table*)malloc(sizeof(avm_table));
    AVM_WIPEOUT(*t);
    
    t->refCounter = 0;
    t->total = 0;
    
    avm_tablebucketsinit(t->strIndexed);
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->funcIndexed);
    
    return t;
}

// Initialize bucket arrays
void avm_tablebucketsinit(avm_table_bucket** p) {
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE; ++i) {
        p[i] = (avm_table_bucket*)0;
    }
}

// Destroy bucket arrays
void avm_tablebucketsdestroy(avm_table_bucket** p) {
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE; ++i) {
        for (avm_table_bucket* b = p[i]; b;) {
            avm_table_bucket* del = b;
            b = b->next;
            avm_memcellclear(&del->key);
            avm_memcellclear(&del->value);
            free(del);
        }
        p[i] = (avm_table_bucket*)0;
    }
}

// Destroy table
void avm_tabledestroy(avm_table* t) {
    avm_tablebucketsdestroy(t->strIndexed);
    avm_tablebucketsdestroy(t->numIndexed);
    avm_tablebucketsdestroy(t->funcIndexed);
    free(t);
}

// Reference counting
void avm_tableincrefcounter(avm_table* t) {
    ++t->refCounter;
}

void avm_tabledecrefcounter(avm_table* t) {
    assert(t->refCounter > 0);
    if (!--t->refCounter) {
        avm_tabledestroy(t);
    }
}

// Get appropriate bucket array and hash for a key
static avm_table_bucket** avm_tablegetbuckets(avm_table* table, avm_memcell* index, unsigned* hash) {
    switch (index->type) {
        case number_m:
            *hash = avm_hash_number(index->data.numVal);
            return table->numIndexed;
            
        case string_m:
            *hash = avm_hash_string(index->data.strVal);
            return table->strIndexed;
            
        case userfunc_m:
            *hash = avm_hash_func(index->data.funcVal);
            return table->funcIndexed;
            
        case libfunc_m:
            *hash = avm_hash_string(index->data.libfuncVal);
            return table->funcIndexed;
            
        case bool_m:
            *hash = avm_hash_number((double)index->data.boolVal);
            return table->numIndexed;
            
        default:
            return NULL;
    }
}

// Check if two memory cells are equal for table indexing
static unsigned char avm_tablekey_equal(avm_memcell* k1, avm_memcell* k2) {
    if (k1->type != k2->type) {
        return 0;
    }
    
    switch (k1->type) {
        case number_m:
            return k1->data.numVal == k2->data.numVal;
        case string_m:
            return strcmp(k1->data.strVal, k2->data.strVal) == 0;
        case userfunc_m:
            return k1->data.funcVal == k2->data.funcVal;
        case libfunc_m:
            return strcmp(k1->data.libfuncVal, k2->data.libfuncVal) == 0;
        case bool_m:
            return k1->data.boolVal == k2->data.boolVal;
        case nil_m:
            return 1;
        default:
            return 0;
    }
}

// Set table element
void avm_tablesetelem(avm_table* table, avm_memcell* index, avm_memcell* content) {
    assert(table && index);
    
    if (index->type == nil_m) {
        avm_error("Table index cannot be nil!");
        return;
    }
    
    if (index->type == undef_m) {
        avm_error("Table index cannot be undefined!");
        return;
    }
    
    unsigned hash;
    avm_table_bucket** buckets = avm_tablegetbuckets(table, index, &hash);
    
    if (!buckets) {
        char* indexStr = strdup(avm_tostring(index));
        avm_error("Illegal table index type: %s", indexStr);
        free(indexStr);
        return;
    }
    
    // Look for existing bucket
    avm_table_bucket* bucket;
    for (bucket = buckets[hash]; bucket; bucket = bucket->next) {
        if (avm_tablekey_equal(&bucket->key, index)) {
            break;
        }
    }
    
    // Handle nil value (remove element)
    if (content && content->type == nil_m) {
        if (bucket) {
            // Remove bucket from chain
            if (buckets[hash] == bucket) {
                buckets[hash] = bucket->next;
            } else {
                avm_table_bucket* prev;
                for (prev = buckets[hash]; prev->next != bucket; prev = prev->next);
                prev->next = bucket->next;
            }
            
            avm_memcellclear(&bucket->key);
            avm_memcellclear(&bucket->value);
            free(bucket);
            table->total--;
        }
        return;
    }
    
    // Update existing bucket or create new one
    if (bucket) {
        avm_assign(&bucket->value, content);
    } else {
        // Create new bucket
        bucket = (avm_table_bucket*)malloc(sizeof(avm_table_bucket));
        bucket->next = buckets[hash];
        buckets[hash] = bucket;
        
        avm_assign(&bucket->key, index);
        avm_assign(&bucket->value, content);
        table->total++;
    }
}

// Get table element
avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index) {
    assert(table && index);
    
    if (index->type == nil_m || index->type == undef_m) {
        return NULL;
    }
    
    unsigned hash;
    avm_table_bucket** buckets = avm_tablegetbuckets(table, index, &hash);
    
    if (!buckets) {
        return NULL;
    }
    
    for (avm_table_bucket* bucket = buckets[hash]; bucket; bucket = bucket->next) {
        if (avm_tablekey_equal(&bucket->key, index)) {
            return &bucket->value;
        }
    }
    
    return NULL;
}

// Traverse table with visitor function
void avm_table_traverse(avm_table* table, avm_table_visitor_t visitor, avm_memcell* result) {
    unsigned index = 0;
    
    // Traverse string-indexed buckets
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE; i++) {
        for (avm_table_bucket* bucket = table->strIndexed[i]; bucket; bucket = bucket->next) {
            visitor(&bucket->key, &bucket->value, &index, result);
        }
    }
    
    // Traverse number-indexed buckets
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE; i++) {
        for (avm_table_bucket* bucket = table->numIndexed[i]; bucket; bucket = bucket->next) {
            visitor(&bucket->key, &bucket->value, &index, result);
        }
    }
    
    // Traverse function-indexed buckets
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE; i++) {
        for (avm_table_bucket* bucket = table->funcIndexed[i]; bucket; bucket = bucket->next) {
            visitor(&bucket->key, &bucket->value, &index, result);
        }
    }
}

// Visitor function for getting keys
void avm_table_keys_visitor(avm_memcell* key, avm_memcell* value, unsigned* index, avm_memcell* result) {
    (void)value; // Unused parameter
    
    avm_memcell indexCell;
    indexCell.type = number_m;
    indexCell.data.numVal = (*index)++;
    
    avm_tablesetelem(result->data.tableVal, &indexCell, key);
}

// Visitor function for copying table
void avm_table_copy_visitor(avm_memcell* key, avm_memcell* value, unsigned* index, avm_memcell* result) {
    (void)index; // Unused parameter
    avm_tablesetelem(result->data.tableVal, key, value);
}

// Convert table to string representation
char* avm_table_tostring(avm_table* table) {
    static char buffer[2048];
    char* ptr = buffer;
    int remaining = sizeof(buffer) - 1;
    int written;
    
    written = snprintf(ptr, remaining, "[ ");
    ptr += written;
    remaining -= written;
    
    if (remaining <= 0) return buffer;
    
    unsigned count = 0;
    
    // Print string-indexed elements
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE && remaining > 0; i++) {
        for (avm_table_bucket* bucket = table->strIndexed[i]; bucket && remaining > 0; bucket = bucket->next) {
            if (count > 0) {
                written = snprintf(ptr, remaining, ", ");
                ptr += written;
                remaining -= written;
                if (remaining <= 0) break;
            }
            
            written = snprintf(ptr, remaining, "{ %s : %s }", 
                             avm_tostring(&bucket->key), 
                             avm_tostring(&bucket->value));
            ptr += written;
            remaining -= written;
            count++;
        }
    }
    
    // Print number-indexed elements
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE && remaining > 0; i++) {
        for (avm_table_bucket* bucket = table->numIndexed[i]; bucket && remaining > 0; bucket = bucket->next) {
            if (count > 0) {
                written = snprintf(ptr, remaining, ", ");
                ptr += written;
                remaining -= written;
                if (remaining <= 0) break;
            }
            
            written = snprintf(ptr, remaining, "{ %s : %s }", 
                             avm_tostring(&bucket->key), 
                             avm_tostring(&bucket->value));
            ptr += written;
            remaining -= written;
            count++;
        }
    }
    
    // Print function-indexed elements
    for (unsigned i = 0; i < AVM_TABLE_HASHSIZE && remaining > 0; i++) {
        for (avm_table_bucket* bucket = table->funcIndexed[i]; bucket && remaining > 0; bucket = bucket->next) {
            if (count > 0) {
                written = snprintf(ptr, remaining, ", ");
                ptr += written;
                remaining -= written;
                if (remaining <= 0) break;
            }
            
            written = snprintf(ptr, remaining, "{ %s : %s }", 
                             avm_tostring(&bucket->key), 
                             avm_tostring(&bucket->value));
            ptr += written;
            remaining -= written;
            count++;
        }
    }
    
    if (remaining > 0) {
        snprintf(ptr, remaining, " ]");
    }
    
    return buffer;
}