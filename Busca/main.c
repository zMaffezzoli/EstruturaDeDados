#include "busca.h"

#include <stdio.h>

void imprime_resultado(
    char *nome,
    ResultadoBusca r
){
    printf(
        "%-20s indice=%4d comparacoes=%4d\n",
        nome,
        r.indice,
        r.comparacoes
    );
}

// gcc -Iinclude src/busca.c main.c -o busca.o && ./busca.o
int main(){

    printf("===== TESTES PEQUENOS =====\n\n");

    int *vet = cria_vetor_ordenado(10);

    imprime_vetor(vet, 10);

    int testes[] = {
        vet[0],
        vet[5],
        999
    };

    for (int i = 0; i < 3; i++){

        int elem = testes[i];

        printf(
            "\nElemento procurado: %d\n",
            elem
        );

        imprime_resultado(
            "Linear",
            busca_linear(vet, 10, elem)
        );

        imprime_resultado(
            "Linear Ordenada",
            busca_linear_ordenada(vet, 10, elem)
        );

        imprime_resultado(
            "Binaria",
            busca_binaria(vet, 10, elem)
        );

        imprime_resultado(
            "Binaria Rec",
            busca_binaria_recursiva(vet, 10, elem)
        );
    }

    libera_vetor(vet);

    printf("\n\n===== EXPERIMENTO =====\n\n");

    printf(
        "%-10s %-10s %-10s %-12s %-10s %-12s\n",
        "n",
        "elem",
        "linear",
        "linear_ord",
        "binaria",
        "bin_rec"
    );

    int tamanhos[] = {
        10,
        100,
        1000,
        10000,
        100000
    };

    for (int i = 0; i < 5; i++){

        int n = tamanhos[i];

        int *v = cria_vetor_ordenado(n);

        int elem = v[n - 1];

        ResultadoBusca l =
            busca_linear(v, n, elem);

        ResultadoBusca lo =
            busca_linear_ordenada(v, n, elem);

        ResultadoBusca b =
            busca_binaria(v, n, elem);

        ResultadoBusca br =
            busca_binaria_recursiva(v, n, elem);

        printf(
            "%-10d %-10d %-10d %-12d %-10d %-12d\n",
            n,
            elem,
            l.comparacoes,
            lo.comparacoes,
            b.comparacoes,
            br.comparacoes
        );

        libera_vetor(v);
    }

    printf("\n");

    return 0;
}