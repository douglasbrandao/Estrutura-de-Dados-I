#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define n 100000

void ordena();
void buscar();
int buscaRecursiva();

int main()
{
    int vetor[n];
    int i;

    int ti = GetTickCount();

    printf("Vetor desordenado:\n\n");
    for(i=0;i<n;i++){
        int r = rand() % 100000;
        vetor[i] = r;
        printf("%d ", vetor[i]);
    }

    int tf = GetTickCount();

    printf("\n\nTempo inicial: %d\n", ti);
    printf("\nTempo final: %d\n", tf);
    printf("\nTempo de execucao para criar o vetor: %d\n", tf-ti);

    printf("\n\n");

    ti = GetTickCount();
    ordena(vetor);
    tf = GetTickCount();

    printf("Vetor ordenado:\n\n");
    for(i=0;i<n;i++){
        printf("%d ", vetor[i]);
    }

    printf("\n\nTempo inicial: %d\n", ti);
    printf("\nTempo final: %d\n", tf);
    printf("\nTempo de execucao para ordenar o vetor: %d\n", tf-ti);


    printf("\n\n---------- BUSCA SE O VALOR EXISTE NO VETOR ORDENADO E MOSTRA SUA POSICAO ----------\n\n");
    int busca;
    printf("Busque um valor de 1 a 10:\n");
    scanf("%d", &busca);

    ti = GetTickCount();
    buscar(vetor, busca);
    tf = GetTickCount();

    printf("\n\nTempo inicial: %d\n", ti);
    printf("\nTempo final: %d\n", tf);
    printf("\nTempo de execucao para buscar um valor no vetor: %d\n", tf-ti);

    printf("\n\n---------------------------- BUSCA RECURSIVA DO CODIGO ANTERIOR ---------------------\n\n");
    int buscar, res;
    printf("Busque um valor de 1 a 10:\n");
    scanf("%d", &buscar);

    ti = GetTickCount();
    res = buscaRecursiva(vetor,0,100000,buscar);
    tf = GetTickCount();

    printf("Vetor pos: [%d]", res);

    printf("\n\nTempo inicial: %d\n", ti);
    printf("\nTempo final: %d\n", tf);
    printf("\nTempo de execucao para buscar recursivamente um valor no vetor: %d\n", tf-ti);
}

void ordena(int vetor[n]){
    int i,j,aux;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(vetor[j] > vetor[j+1]){
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
}

void buscar(int vetor[n], int num){
    int i=0, m, f=n-1;
    while(i<=f){
        m = (i+f)/2;
        if(vetor[m] == num){
            printf("O vetor de valor [%d] esta na posicao [%d]", vetor[m], m);
            break;
        }
        else{
            if(vetor[m] < num){
                i=m+1;
            }
            else{
                f=m-1;
            }
        }
    }
    if(i>f){
        printf("\n\nO numero nao existe no vetor ordenado!\n\n");
    }
}

int buscaRecursiva(int vetor[], int i, int f, int b){
    int m;
    m=(i+f)/2;
    if(i<=f){
        if(vetor[m] == b){
            return m;
        }
        else{
            if(vetor[m]<b){
                return buscaRecursiva(vetor,m+1,f,b);
            }
            else{
                return buscaRecursiva(vetor,i,m-1,b);
            }
        }
    }
    else{
        return -1;
    }
}
