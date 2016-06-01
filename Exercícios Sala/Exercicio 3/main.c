#include <stdio.h>
#include <stdlib.h>
#include "iStack.h"

int main(){
    Stack pilha;
    init(&pilha);
    int num, r;
    printf("Converter Decimal para Binario:\n");
    scanf("%i", &num);
    while (num != 0){
        r = num%2;
        push(&pilha, r);
        num = num/2;
    }
    show(&pilha);
}
