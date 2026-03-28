#include "pilha.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Pilha *pilha_cria(void){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));

    if (p == NULL){ // Caso malloc falhe
        printf("Erro de alocação\n");
        exit(1);
    }

    p->topo = NULL;
    return p;
}

void pilha_push(Pilha *p, float v){
    NoLista *novo = (NoLista*) malloc(sizeof(NoLista));

    novo->info = v;
    novo->prox = p->topo;

    p->topo = novo;
}

float pilha_pop(Pilha *p){
    if (p->topo == NULL){
        // printf("Erro ao retirar elemento da pilha. Pilha vazia.\n");
        // exit(1);
        return 0; // Somente para calculadora, caso contrário comentar essa e descomentar as acima
    }

    float valor = p->topo->info;
    NoLista *temp = p->topo;

    p->topo = p->topo->prox;
    free(temp);

    return valor;
}

int pilha_vazia(Pilha *p){
    return p->topo == NULL;
}

float pilha_top(Pilha *p){
    if (p->topo == NULL){
        printf("Erro ao retornar topo da pilha. Pilha vazia.\n");
        exit(1);
    }

    return p->topo->info;
}

void pilha_libera(Pilha *p){
    // Passa um a um apagando e apontando para o prox
    while (p->topo != NULL){
        NoLista *temp = p->topo;
        p->topo = p->topo->prox;
        free(temp);
    }

    free(p); 
}

void pilha_imprime(Pilha *p){
    if (p->topo == NULL){
        printf("Erro ao imprimir pilha. Pilha vazia.\n");
        exit(1);
    }
    
    NoLista *temp = p->topo;
    while (temp != NULL){
        printf("%f\n", temp->info);
        temp = temp->prox;
    }
}

Calc *calc_cria(char *f){
    Calc *calc = (Calc*) malloc(sizeof(Calc));

    if (calc == NULL){ // Caso malloc falhe
        printf("Erro de alocação de Calc\n");
        exit(1);
    }

    strncpy(calc->f, f, sizeof(calc->f));
    calc->p = pilha_cria();

    return calc;
}

void calc_operando(Calc *c, float v){
    pilha_push(c->p, v);

    printf(c->f, pilha_top(c->p));
} 

void calc_operador(Calc *c, char op){
    switch (op) {
        case '+': {
            float b = pilha_pop(c->p);
            float a = pilha_pop(c->p);
            
            calc_operando(c, a + b);

            break;
        }
        case '-': {
            float b = pilha_pop(c->p);
            float a = pilha_pop(c->p);

            calc_operando(c, a - b);

            break;
        }
        case '*': {
            float b = pilha_pop(c->p);
            float a = pilha_pop(c->p);
            
            calc_operando(c, a * b);

            break;
        }
        case '/': {
            float b = pilha_pop(c->p);

            if (b == 0){
                printf("Erro. Divisão por zero\n");
                exit(1);
            }

            float a = pilha_pop(c->p);
            
            calc_operando(c, a / b);

            break;
        }
    }
}


void calc_libera(Calc *c){
    pilha_libera(c->p);
    free(c);
}
