#ifndef FUNCTIONS_H
#define FUNCTIONS_H

double add(double num1, double num2);
double subtract(double num1 , double num2);
double multiply(double num1, double num2);
double divide(double num1, double num2);
double applyOperator(char operator, double num1, double num2);
int precedence(char operator);
double parse(const char *equation);

#endif