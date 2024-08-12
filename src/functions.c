#include "../include/stack.h"
#include "stack.c"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

double add(double num1, double num2){
    return num1 + num2;
}

double subtract(double num1 , double num2){
    return num1 - num2;
}

double multiply(double num1, double num2){
    return num1 * num2;
}

double divide(double num1, double num2){
    return num1 / num2;
}

double applyOperator(char operator, double num1, double num2){
    switch(operator){
        case '+': return add(num1,num2);
        case '-': return subtract(num1, num2);
        case '*': return multiply(num1,num2);
        case 'x': return multiply(num1,num2);
        case '/': 
            if(num2 == 0){
                exit(EXIT_FAILURE);
            }
            return divide(num1,num2);
        default: exit(EXIT_FAILURE);
    }
        
}



double parse(const char *equation[]){
    
}

char** getslices(int argv, char *argc[]){
 // sample input 5 + 3 * (1 + 4) / (2 / 3)
 // returns the slices in order, to aid in parsing
 // returns ['2 / 3', '1 + 4', 5 * 3]
}

void parseInput(int argv, char *argc[], ValueStack *vals, OperationStack *Ops){
 //sample input 5 + 3
 // op stack - > +
 // Val Stack -> 5 , 3
}