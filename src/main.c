#include<stdbool.h>
#include<stdio.h>

// Enumerator to make readable instruction names
typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

// Simple program adding two numbers in stack
// implemented as an array to be iterated over
const int program[] = {
    PSH, 2,
    PSH, 2,
    ADD,
    POP,
    HLT
};

// Init instruction pointer/program counter
int ip = 0;
int sp = -1;
int stack[256];

// Preventing infinite loop running
bool running = true;

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
            stack[sp] = program[++ip];
            break;
        }
        case POP: {
            int val_popped = stack[sp--];
            printf("popped %d\n", val_popped);
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
    }
}

int main() {
    while(running) {
        eval(fetch());
        ip++;
    }

   return 0;
}
