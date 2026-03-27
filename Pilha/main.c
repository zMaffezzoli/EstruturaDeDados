#include "pilha.h"
#include <stdio.h>

// gcc -Iinclude main.c src/pilha.c -o pilha.out && ./pilha.out
int main(){
    Pilha *pilha = pilha_cria();
    pilha_push(pilha, 1);
    pilha_push(pilha, 2);
    pilha_push(pilha, 3);
    pilha_push(pilha, 4);
    pilha_push(pilha, 5);


    printf("Pilha com 5  elementos\n");
    pilha_imprime(pilha);

    printf("\n");

    printf("Topo da lista %f\n", pilha_top(pilha));
    printf("Pilha vazia: %d\n", pilha_vazia(pilha));

    printf("\n");

    printf("Retirando topo da lista\n");
    pilha_pop(pilha);
    pilha_imprime(pilha);

    printf("\n");

    printf("Liberando a pilha\n");
    pilha_libera(pilha);
    printf("Pilha vazia: %d\n", pilha_vazia(pilha));
    
    return 0;
}