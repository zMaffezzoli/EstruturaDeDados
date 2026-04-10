#ifndef FILA_H
#define FILA_H

struct fila {
    int tam; // capacidade maxima da fila;
    int n; // quantidade atual de elementos armazenados
    int ini; // index da posicao do proximo elemento a ser removido
    int *vet; // vetor de inteiros usado para armazenar os elementos.
};

typedef struct fila Fila;

Fila *fila_cria(int tam);
void fila_enqueue(Fila *f, int v);
int fila_dequeue(Fila *f);
int fila_vazia(Fila *f);
void fila_imprime(Fila *f);
void fila_reset(Fila *f);
Fila *fila_concatena(Fila *f1, Fila *f2);
Fila *fila_merge(Fila *f1, Fila *f2);
void fila_libera(Fila *f);
void fila_valida(Fila *f);
#endif