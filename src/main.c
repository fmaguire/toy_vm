#include<stdbool.h>
#include<stdio.h>

// Enumerator to make readable instruction names
typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    RET,
    HLT
} InstructionSet;

typedef enum {
    A,
    B,
    C,
    D,
    E,
    F,
    NUM_OF_REGISTERS
} Registers;

int registers[NUM_OF_REGISTERS];



// Simple program adding two numbers in stack
// implemented as an array to be iterated over
const int program[] = {
    PSH, 2,
    PSH, 2,
    ADD,
    POP,
    SET, B, 5,
    RET, B,
    HLT
};

// Init instruction pointer/program counter
int ip = 0;
int sp = -1;
int stack[256];
int stacksize = sizeof(stack)/sizeof(int);

// Preventing infinite loop running
bool running = true;
bool crash = false;

int fetch(){
    return program[ip];
}

void eval(int instr) {
    switch (instr) {
        case HLT: {
            running = false;
            break;
        }
        case PSH: {
            sp++;
            if (sp > stacksize){
                crash = true;
                printf("Stack overflow\n");
                break;
            }
            stack[sp] = program[++ip];
            break;
        }
        case POP: {
            if (sp < 0) {
                crash = true;
                printf("Stack underflow\n");
                break;
            }
            int val_popped = stack[sp--];
            printf("Popped %d\n", val_popped);
            break;
        }
        case ADD: {
            int a = stack[sp--];
            int b = stack[sp--];
            int result = a+b;
            sp++;
            stack[sp] = result;
            break;
        }
        case SET: {
            int reg = program[++ip];
            int val = program[++ip];
            registers[reg] = val;
            break;
        }
        case RET: {
            int reg = program[++ip];
            int val_ret = registers[reg];
            printf("Retrieved %d from reg %d\n", val_ret, reg);
            break;
        }
    }
}

int main() {
    while(running && !crash) {
        eval(fetch());
        ip++;
    }

   return 0;
}
