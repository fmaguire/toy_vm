
// Enumerator to make readable instruction names
typedef enum {
    PSH,
    ADD,
    POP,
    SET,
    HLT
} InstructionSet;

// Simple program adding two numbers in stack
const int program[] = {
    PSH, 2,
    PSH, 2,
    ADD,
    POP,
    HLT
};


int main() {
    return 0;
}
