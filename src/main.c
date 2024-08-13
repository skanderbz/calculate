#include "../include/stack.h"
#include "../include/functions.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main(int argv, char *argc[]){
    if (argv != 2){
        printf("Usage; calculate \"expression\"\n");
        return 1;
    }
    else {
        double num = parse(argc[1]);
        printf("%f\n",num);
        return 0;
    }
}