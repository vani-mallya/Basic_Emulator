#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100
#define PROGRAM_SIZE 256

// Opcodes
#define NOP  0
#define PUSH 1
#define POP  2
#define ADD  3
#define SUB  4
#define JZ   5
#define JMP  6
#define SWAP 7

int stack[STACK_SIZE];
int sp = -1; 

unsigned char program[PROGRAM_SIZE];
int program_size = 0;

void push(int value) {
    if (sp >= STACK_SIZE - 1) {
        printf("Stack overflow.\n");
        exit(1);
    }
    stack[++sp] = value;
}

int pop() {
    if (sp < 0) {
        printf("Stack underflow.\n");
        exit(1);
    }
    return stack[sp--];
}

void run() {
    int pc = 0;  

    while (pc < program_size) {
        unsigned char instr = program[pc];

        int opcode  = instr >> 5;
        int operand = instr & 0x1F;

        switch (opcode) {
            case NOP:
                pc++;
                break;

            case PUSH:
                push(operand);
                pc++;
                break;

            case POP:
                pop();
                pc++;
                break;

            case ADD:
                if (sp < 1 || operand > sp) {
                    printf("Cannot perform addition.\n");
                    exit(1);
                }
                stack[sp] = stack[sp] + stack[operand];
                pc++;
                break;

            case SUB:
                if (sp < 1 || operand > sp) {
                    printf("Cannot perform subtraction\n");
                    exit(1);
                }
                stack[sp] = stack[sp] - stack[operand];
                pc++;
                break;

            case JZ:
                if (sp < 0) {
                    printf("Cannot jump to zero as the stack is empty.\n");
                    exit(1);
                }
                if (stack[sp] == 0)
                    pc = operand;
                else
                    pc++;
                break;

            case JMP:
                pc = operand;
                break;

            case SWAP:
                if (sp < 0 || operand > sp) {
                    printf("Invalid swap.\n");
                    exit(1);
                }
                {
                    int temp = stack[sp];
                    stack[sp] = stack[operand];
                    stack[operand] = temp;
                }
                pc++;
                break;

            default:
                printf("Instruction not recognised.\n");
                exit(1);
        }
    }
}

int main() {
    program[0] = (PUSH << 5) | 5;   
    program[1] = (PUSH << 5) | 3;   
    program[2] = (ADD  << 5) | 0;   

    program_size = 3;

    run();

    printf("Top of stack: %d\n", stack[sp]);  
    return 0;
}
