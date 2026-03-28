#ifndef PILHA_H
#define PILHA_H

struct noLista {
    float info;
    struct noLista *prox;
};

typedef struct noLista NoLista;

struct pilha {
    NoLista *topo;
};

typedef struct pilha Pilha;

struct calc {
    char f[21]; /* formato para expressao, por exemplo "%.2f\n" */
    Pilha *p; // Pilha da expressao
};

typedef struct calc Calc;


Pilha *pilha_cria(void);
void pilha_push(Pilha *p, float v);
float pilha_pop(Pilha *p);
int pilha_vazia(Pilha *p);
float pilha_top(Pilha *p);
void pilha_libera(Pilha *p);
void pilha_imprime(Pilha *p);
Calc *calc_cria(char *f);
void calc_operando(Calc *c, float v);
void calc_operador(Calc *c, char op);
void calc_libera(Calc *c);

#endif