
typedef struct Instructions {
    int opcode;
    int funct;
    char actionType;
    char *actionName;
} Instruction;

typedef struct {
    char *opcode;
    char *rs;
    char *rt;
    char *rd;
    char *funct;
    char *notInUse;
} R;


typedef struct {
    char *opcode;
    char *rs;
    char *rt;
    char *immed;
} I;


typedef struct {
    char *opcode;
    char reg;
    char *address;
} J;


typedef struct {
    int address;
    char *sourceCode;
    char *machineCode;
} FinalTable;

