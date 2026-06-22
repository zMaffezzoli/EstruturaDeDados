#include "fila.h"
#include <stdio.h>

// gcc -Iinclude main.c src/fila.c -o fila.o && ./fila.o
int main(){
    Fila *fila = fila_cria(5);

    printf("Chegando senhas 101, 102, 103, 104, 105\n");
    fila_enqueue(fila, 101);
    fila_enqueue(fila, 102);
    fila_enqueue(fila, 103);
    fila_enqueue(fila, 104);
    fila_enqueue(fila, 105);

    printf("Atendendo uma senha\n");
    fila_dequeue(fila);

    printf("Chegando senha 106\n");
    fila_enqueue(fila, 106);

    printf("Fila atual:\n");
    fila_imprime(fila);

    printf("Reinicio do atendimento\n");
    fila_reset(fila);

    printf("A fila de atendimento está vazia: %d\n", fila_vazia(fila));
    return 0;
}