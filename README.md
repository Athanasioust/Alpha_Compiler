Alpha Language Compiler & Virtual Machine
BUILDING THE COMPILER AND VM:

Place all VM files (avm.h, avm.c, avm_execution.c, avm_functions.c, avm_tables.c, avm_libfuncs.c) in a "vm/" directory
Build everything:
make

This creates:

alpha.exe (the compiler)
avm.exe (the virtual machine)

RUNNING ALPHA PROGRAMS:

Compile an Alpha source file:
./alpha.exe your_program.asc
This generates alpha.abc (bytecode file)
Run the bytecode in the VM:
./avm.exe alpha.abc

EXAMPLE:
echo 'print("Hello Alpha!");' > hello.asc
./alpha.exe hello.asc
./avm.exe alpha.abc
CLEANING:
make clean
PROJECT STRUCTURE:
src/        - Compiler source code
vm/         - Virtual machine source code
include/    - Header files
tests/      - Test programs
Makefile    - Build system