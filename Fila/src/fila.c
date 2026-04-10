#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

Fila *fila_cria(int tam){
    if (tam <= 0){
        printf("Erro: tamanho inválido.\n");
        exit(1);
    }

    Fila *fila = (Fila*) malloc(sizeof(Fila));

    if (fila == NULL){
        printf("Erro de alocação.\n");
        exit(1);
    }

    fila->tam = tam;
    fila->n = 0;
    fila->ini = 0;

    fila->vet = (int*) malloc(tam * sizeof(int)); 

    if (fila->vet == NULL){
        printf("Erro de alocação do vetor.\n");
        free(fila);
        exit(1);
    }

    return fila;
}

void fila_enqueue(Fila *f, int v){
    fila_valida(f);
    
    if (f->tam == f->n){
        printf("Erro ao inserir. Fila cheia.\n");
        exit(1);
    }

    int fim = (f->ini + f->n) % f->tam; // Fila circular
    f->vet[fim] = v;

    f->n++;
}

int fila_vazia(Fila *f){
    fila_valida(f);

    return f->n == 0;
}

int fila_dequeue(Fila *f){
    if (fila_vazia((f))){
        printf("Erro ao retirar elemento da fila. Fila vazia.\n");
        exit(1);
    }

    int valor = f->vet[f->ini];
    
    f->ini = (f->ini + 1) % f->tam;
    f->n--;

    return valor;
}

void fila_imprime(Fila *f){
    fila_valida(f);
    
    int i = 0;
    int index = f->ini;
    while(i < f->n){
        printf("%d\n", f->vet[index]);
        index = (index + 1) % f->tam;
        i++;
    }
}

void fila_reset(Fila *f){
    fila_valida(f);

    f->ini = 0;
    f->n = 0;
}

Fila *fila_concatena(Fila *f1, Fila *f2){
    fila_valida(f1);
    fila_valida(f2);
    
    Fila *nova = fila_cria(f1->n + f2->n);

    int i = 0;
    int index = f1->ini;
    while(i < f1->n){
        fila_enqueue(nova, f1->vet[index]);
        index = (index + 1) % f1->tam;
        i++;
    }

    i = 0;
    index = f2->ini;
    while(i < f2->n){
        fila_enqueue(nova, f2->vet[index]);
        index = (index + 1) % f2->tam;
        i++;
    }

    return nova;
}

Fila *fila_merge(Fila *f1, Fila *f2){
    fila_valida(f1);
    fila_valida(f2);

    Fila *nova = fila_cria(f1->n + f2->n);

    int i_f1 = 0, i_f2 = 0;
    int index_f1 = f1->ini;
    int index_f2 = f2->ini;

    while (i_f1 < f1->n || i_f2 < f2->n){
        if (i_f1 < f1->n){
            fila_enqueue(nova, f1->vet[index_f1]);
            index_f1 = (index_f1 + 1) % f1->tam;
            i_f1++;
        }
        
        if (i_f2 < f2->n){
            fila_enqueue(nova, f2->vet[index_f2]);
            index_f2 = (index_f2 + 1) % f2->tam;
            i_f2++;
        }
    }

    return nova;
}

void fila_libera(Fila *f){
    if (f == NULL) return;

    free(f->vet);
    free(f);
}

void fila_valida(Fila *f){
    if (f == NULL){
        printf("Fila nula\n");
        exit(1);
    }
}
