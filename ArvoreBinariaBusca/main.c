#include <stdio.h>

#include "arvoreBusca.h"

// gcc -Iinclude src/arvoreBusca.c main.c -o arvoreBusca.o && ./arvoreBusca.o
int main(void){
    ArvoreBusca *a = abb_cria();

    int valores[] = {
        50, 30, 70,
        20, 40, 60, 80,
        35, 45, 55, 65, 75, 85,
        10, 25
    };

    int n = sizeof(valores) / sizeof(valores[0]);

    int i;

    for(i = 0; i < n; i++){
        abb_insere(a, valores[i]);
    }

    printf("Codigos em ordem crescente:\n");
    abb_imprime_crescente(a);

    printf("\n");

    printf("Codigos em ordem decrescente:\n");
    abb_imprime_decrescente(a);

    printf("\n");

    printf("Numero de nos: %d\n",
           abb_num_nos(a));

    printf("Numero de folhas: %d\n",
           abb_folhas(a));

    printf("Altura da arvore: %d\n",
           abb_altura(a));

    printf("\n");

    printf("Buscas existentes:\n");

    printf("35 -> %s\n",
           abb_pertence(a,35)
           ? "encontrado"
           : "nao encontrado");

    printf("70 -> %s\n",
           abb_pertence(a,70)
           ? "encontrado"
           : "nao encontrado");

    printf("85 -> %s\n",
           abb_pertence(a,85)
           ? "encontrado"
           : "nao encontrado");

    printf("\n");

    printf("Buscas inexistentes:\n");

    printf("11 -> %s\n",
           abb_pertence(a,11)
           ? "encontrado"
           : "nao encontrado");

    printf("90 -> %s\n",
           abb_pertence(a,90)
           ? "encontrado"
           : "nao encontrado");

    printf("100 -> %s\n",
           abb_pertence(a,100)
           ? "encontrado"
           : "nao encontrado");

    printf("\n");

    printf("Removendo folha (10)\n");
    abb_retira(a,10);
    abb_imprime_crescente(a);

    printf("\n");

    printf("Removendo no com um filho (20)\n");
    abb_retira(a,20);
    abb_imprime_crescente(a);

    printf("\n");

    printf("Removendo no com dois filhos (70)\n");
    abb_retira(a,70);
    abb_imprime_crescente(a);

    printf("\n");

    abb_libera(a);

    return 0;
}