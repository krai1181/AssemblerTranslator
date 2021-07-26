

typedef struct Instructions {
    int opcode;
    int funct;
    char actionType;
    char *actionName;
} Instruction;

typedef struct {
    int opcode;
    int rs;
    int rt;
    int rd;
    char *funct;
    char *notInUse;
} R;


typedef struct {
    int opcode;
    int rs;
    int rt;
    char *immed;
} I;


typedef struct {
    int opcode;
    int reg;
    char *address;
} J;

typedef struct {
    R r;
    I i;
    J j;
} Row;

typedef struct {
    char *address;
    char *sourceCode;
    char *machineCode;
} FinalTable;

