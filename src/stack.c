#include "../include/stack.h"
#include <stdio.h>
#include <stdlib.h>

// Functions for Value Stack

ValueStack* newValueStack(){
    ValueStack *S = (ValueStack*)malloc(sizeof(ValueStack));
    S->top = -1;
    return S;
}

bool valstackEmpty(ValueStack *s){
    return (s->top == -1);
}

bool valstackFull(ValueStack *s){
    return (s->top == (int)MAX_STACK_SIZE - 1);
}

double popVal(ValueStack *s){
    if (valstackEmpty(s)){
        exit(EXIT_FAILURE);
    }

    double value = s->nums[s->top];
    s->top--;
    return value;
}

void pushVal(ValueStack *s, double item){
    if (valstackFull(s)){
        fprintf(stderr, "Stack overflow: cannot push onto a full stack\n");
        exit(EXIT_FAILURE);
    }
    s->top++;
    s->nums[s->top] = item;
}

double peekVal(ValueStack *s){
    return (s->nums[s->top]);
}


// OpStack Operations

OperationStack* newOperationStack(){
    OperationStack *newOP = (OperationStack*)malloc(sizeof(OperationStack));
    newOP->top = -1;
    return newOP;
}

bool opstackEmpty(OperationStack *s){
    return (s->top == -1);
}
bool opstackFull(OperationStack *s){
    return (s->top == (int)MAX_STACK_SIZE - 1);
}

char popOp(OperationStack *s){
    if (opstackEmpty(s)){
        exit(EXIT_FAILURE);
    }
    char item = s->ops[s->top];
    s->top--;
    return item;
}


void pushOp(OperationStack *s, char item){
    if  (opstackFull(s)){
            fprintf(stderr, "Stack overflow: cannot push onto a full stack\n");
            exit(EXIT_FAILURE);
        }
    s->top++;
    s->ops[s->top] = item;
}
    

char peekOp(OperationStack *s){
    return (s->ops[s->top]);
}
