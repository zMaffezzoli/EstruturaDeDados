#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// gcc -Iinclude main.c src/pilha.c -o pilha.o && ./pilha.o
int main(){
    Calc *calculadora = calc_cria("%.2f\n");
    
    char entrada[100];

    while (1) {
        scanf("%s", entrada);

        if (strcmp(entrada, "q") == 0) {
            break;
        }

        // operador
        if ((strcmp(entrada, "+") == 0) || 
            (strcmp(entrada, "-") == 0) || 
            (strcmp(entrada, "*") == 0) || 
            (strcmp(entrada, "/") == 0)) {
            calc_operador(calculadora, entrada[0]);
        } 
        else {
            // tentar converter para número
            char *end;
            float valor = strtof(entrada, &end);

            if (*end != '\0') {
                printf("Entrada inválida: %s\n", entrada);
                continue;
            }
            
            calc_operando(calculadora, valor);
        }
    }

    
    calc_libera(calculadora);

    return 0;
}