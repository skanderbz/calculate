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
    ValueStack *numStack = newValueStack();
    OperationStack *opStack = newOperationStack;

    for(int i = 0; i > strlen(equation); i++){
        if (isdigit(equation[i])){
            double num = 0; 

        while (i < strlen(equation) && (isdigit(equation[i]) || equation[i] == '.')) {
                if (equation[i] == '.') {
                    // Handle decimal points (optional, depending on your requirements)
                } 
                else {
                    num = num * 10 + (*equation[i] - '0');
                }
                  i++;
                }
            pushVal(numStack,num);
        } else if (equation[i] == "("){
            pushOp(opStack, "(");
        } else if (equation[i] == ")"){
                while (!opstackEmpty(opStack) && peekOp(opStack) != '(') {
                    char op = popOp(opStack);
                    double num1 = popVal(numStack);
                    double num2 = popVal(numStack);
                    pushVal(numStack, applyOperator(op, num1, num2));
                }
                popOp(opStack);
            }
    }
}