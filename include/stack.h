#ifndef STACK_H

#define STACK_H
#include <stdbool.h>

#define MAX_STACK_SIZE 100

typedef struct 
{
    double nums[(int)MAX_STACK_SIZE];
    int top;
} ValueStack ;

typedef struct 
{
    char ops[(int)MAX_STACK_SIZE];
    int top;
} OperationStack;

// Function prototypes for the Value Stack

ValueStack* newValueStack();
bool valstackEmpty(ValueStack *s);
bool valstackFull(ValueStack *s);
double popVal(ValueStack *s);
void pushVal(ValueStack *s, double item);
double peekVal(ValueStack *s);

// Function prototypes for Operation Stack

OperationStack* newOperationStack();
bool opstackEmpty(OperationStack *s);
bool opstackFull(OperationStack *s);
double popOp(OperationStack *s);
void pushOp(OperationStack *s, char item);
double peekOp(OperationStack *s);


// Yipee!
#endif