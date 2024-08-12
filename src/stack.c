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
    return (s->top == MAX_STACK_SIZE -1);
}

double popVal(ValueStack *s){
    if (valstackEmpty(s)){
        exit(EXIT_FAILURE);
    }

    double value = s->nums[s->top];
    s->top--;
}