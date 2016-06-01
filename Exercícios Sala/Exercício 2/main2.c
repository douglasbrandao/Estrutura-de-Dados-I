#include <stdio.h>
#include <stdlib.h>
#include "cStack.h"

int main(){
    char original[6] = "arara\0";
    char modificada[6];
    Stack pilha;
    init(&pilha);

    int i = 0;
    for(i=0;i<5;i++){
        push(&pilha, original[i]);
    }

    for(i=0;i<5;i++){
        modificada[i] = pop(&pilha);
    }

    printf("%s",(strcmp(original, modificada)==0)?"Palindroma!\n":"Nao e palindroma!\n");

    return EXIT_SUCCESS;
}
