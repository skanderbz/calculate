#include "../include/stack.h"
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
        case '+': return add(num1, num2);
        case '-': return subtract(num1, num2);
        case '*': return multiply(num1, num2);
        case 'x': return multiply(num1, num2);
        case '/': 
            if (num2 == 0) {
                fprintf(stderr, "Division by zero error.\n");
                exit(EXIT_FAILURE);
            }
            return divide(num1, num2);
        default: 
            fprintf(stderr, "Unknown operator: %c\n", operator);
            exit(EXIT_FAILURE);
    }
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        default: return 0;
    }
}

double parse(const char *equation){
    ValueStack *numStack = newValueStack();
    OperationStack *opStack = newOperationStack();

    for(size_t i = 0; i < strlen(equation); i++){
        if (isspace(equation[i])) {
            continue; // Skip spaces
        }

        if (isdigit(equation[i]) || equation[i] == '.') {
            double num = 0; 
            double divisor = 1.0;
            int isDecimal = 0;

            while (i < strlen(equation) && (isdigit(equation[i]) || equation[i] == '.')) {
                if (equation[i] == '.') {
                    isDecimal = 1;
                } else {
                    if (isDecimal) {
                        divisor *= 10.0;
                        num = num + (equation[i] - '0') / divisor;
                    } else {
                        num = num * 10 + (equation[i] - '0');
                    }
                }
                i++;
            }
            i--; // Adjust index because it will be incremented in the loop
            pushVal(numStack, num);

        } else if (equation[i] == '(') {
            pushOp(opStack, '(');

        } else if (equation[i] == ')') {
            while (!opstackEmpty(opStack) && peekOp(opStack) != '(') {
                char op = popOp(opStack);
                double num2 = popVal(numStack);
                double num1 = popVal(numStack);
                pushVal(numStack, applyOperator(op, num1, num2));
            }
            popOp(opStack); // Remove the '(' from the stack

        } else if (strchr("+-*/", equation[i])) {
            while (!opstackEmpty(opStack) && precedence(peekOp(opStack)) >= precedence(equation[i])) {
                char op = popOp(opStack);
                double num2 = popVal(numStack);
                double num1 = popVal(numStack);
                pushVal(numStack, applyOperator(op, num1, num2));
            }
            pushOp(opStack, equation[i]);
        }
    }

    while (!opstackEmpty(opStack)) {
        char op = popOp(opStack);
        double num2 = popVal(numStack);
        double num1 = popVal(numStack);
        pushVal(numStack, applyOperator(op, num1, num2));
    }

    double finalResult = popVal(numStack);
    free(numStack); 
    free(opStack); 
    return finalResult;
}
