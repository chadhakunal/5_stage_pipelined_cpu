#riscv64-unknown-elf-objdump -Dp /shared/cse502/tests/wp1/prog1.o >> wp1prog1dump.s # Decompile from o file to assembly
#!/bin/bash
# This script assembles a RISC-V assembly file into an object file
# and optionally decompiles an object file to assembly.

# Program name and path
PROG_NAME=test1
PROG_PATH=/home/${USER}/cse_502_cpu/tests/${PROG_NAME}

# Ensure the script stops on errors
set -e

# Assemble the program
riscv64-unknown-elf-gcc -c ${PROG_PATH}.s -o ${PROG_PATH}.o

echo "Assembly completed: ${PROG_PATH}.o generated."