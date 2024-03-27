#include "func_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static func_stack_T head = NULL;

struct func_stack{
    int scope;
    struct func_stack* next;
};
// Function to push a new scope to the stack
void func_stack_push(int scope){
    func_stack_T temp = malloc(sizeof(struct func_stack));
    temp->scope = scope;
    temp->next = head;
    head = temp;
}
// Function to get the top of the stack
int func_stack_top(){
    if(!head) return 0;
    return head->scope;
}
// Function to pop the top of the stack
void func_stack_pop(){
    assert(head);
    func_stack_T temp = head;
    head = head->next;
    free(temp);
}