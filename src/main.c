#include "../include/stack.h"
#include "../include/functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argv, char *argc[]) {
    if (argv < 2) {
        printf("Usage: calculate expression\n");
        return 1;
    }

    // Calculate the total length of the expression
    size_t expression_length = 0;
    for (int i = 1; i < argv; i++) {
        expression_length += strlen(argc[i]);
    }

    // Allocate space for the full expression
    char *expression = malloc(expression_length + 1);
    if (!expression) {
        perror("Failed to allocate memory");
        return 1;
    }

    // Concatenate the command-line arguments into a single expression string
    expression[0] = '\0';
    for (int i = 1; i < argv; i++) {
        strcat(expression, argc[i]);
    }

    // Parse and calculate the expression
    double num = parse(expression);

    // Print the result
    printf("%f\n", num);

    // Free allocated memory
    free(expression);

    return 0;
}
