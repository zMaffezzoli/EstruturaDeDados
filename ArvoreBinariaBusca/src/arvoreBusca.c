#include "arvoreBusca.h"

#include <stdlib.h>
#include <stdio.h>

ArvoreBusca *abb_cria(void){
    ArvoreBusca *a =
        (ArvoreBusca*) malloc(sizeof(ArvoreBusca));

    if(a == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }

    a->raiz = NULL;

    return a;
}

int abb_vazia(ArvoreBusca *a){
    return (a == NULL || a->raiz == NULL);
}

static NoArvoreBusca *busca_no(NoArvoreBusca *no, int v){
    if(no == NULL)
        return NULL;

    if(v == no->info)
        return no;

    if(v < no->info)
        return busca_no(no->esq, v);

    return busca_no(no->dir, v);
}

NoArvoreBusca *abb_busca(ArvoreBusca *a, int v){
    if(a == NULL)
        return NULL;

    return busca_no(a->raiz, v);
}

int abb_pertence(ArvoreBusca *a, int v){
    return abb_busca(a, v) != NULL;
}

static NoArvoreBusca *insere_no(NoArvoreBusca *no, int v){
    if(no == NULL){

        NoArvoreBusca *novo =
            (NoArvoreBusca*) malloc(sizeof(NoArvoreBusca));

        if(novo == NULL){
            printf("Erro de alocacao\n");
            exit(1);
        }

        novo->info = v;
        novo->esq = NULL;
        novo->dir = NULL;

        return novo;
    }

    if(v < no->info)
        no->esq = insere_no(no->esq, v);
    else
        no->dir = insere_no(no->dir, v);

    return no;
}

void abb_insere(ArvoreBusca *a, int v){
    if(a == NULL)
        return;

    a->raiz = insere_no(a->raiz, v);
}

static int conta_nos(NoArvoreBusca *no){
    if(no == NULL)
        return 0;

    return 1
        + conta_nos(no->esq)
        + conta_nos(no->dir);
}

int abb_num_nos(ArvoreBusca *a){
    if(a == NULL)
        return 0;

    return conta_nos(a->raiz);
}

static int conta_folhas(NoArvoreBusca *no){
    if(no == NULL)
        return 0;

    if(no->esq == NULL &&
       no->dir == NULL)
        return 1;

    return conta_folhas(no->esq)
         + conta_folhas(no->dir);
}

int abb_folhas(ArvoreBusca *a){
    if(a == NULL)
        return 0;

    return conta_folhas(a->raiz);
}

static int altura_no(NoArvoreBusca *no){
    if(no == NULL)
        return -1;

    int he = altura_no(no->esq);
    int hd = altura_no(no->dir);

    return 1 + (he > hd ? he : hd);
}

int abb_altura(ArvoreBusca *a){
    if(a == NULL)
        return -1;

    return altura_no(a->raiz);
}

static void imprime_crescente_no(NoArvoreBusca *no){
    if(no == NULL)
        return;

    imprime_crescente_no(no->esq);

    printf("%d ", no->info);

    imprime_crescente_no(no->dir);
}

void abb_imprime_crescente(ArvoreBusca *a){
    if(a == NULL){
        printf("\n");
        return;
    }

    imprime_crescente_no(a->raiz);

    printf("\n");
}

static void imprime_decrescente_no(NoArvoreBusca *no){
    if(no == NULL)
        return;

    imprime_decrescente_no(no->dir);

    printf("%d ", no->info);

    imprime_decrescente_no(no->esq);
}

void abb_imprime_decrescente(ArvoreBusca *a){
    if(a == NULL){
        printf("\n");
        return;
    }

    imprime_decrescente_no(a->raiz);

    printf("\n");
}

static NoArvoreBusca *menor_no(NoArvoreBusca *no){
    while(no->esq != NULL)
        no = no->esq;

    return no;
}

static NoArvoreBusca *retira_no(NoArvoreBusca *no, int v){
    if(no == NULL)
        return NULL;

    if(v < no->info){
        no->esq = retira_no(no->esq, v);
    }
    else if(v > no->info){
        no->dir = retira_no(no->dir, v);
    }
    else{

        if(no->esq == NULL &&
           no->dir == NULL){

            free(no);
            return NULL;
        }

        if(no->esq == NULL){

            NoArvoreBusca *aux = no->dir;

            free(no);

            return aux;
        }

        if(no->dir == NULL){

            NoArvoreBusca *aux = no->esq;

            free(no);

            return aux;
        }

        NoArvoreBusca *aux =
            menor_no(no->dir);

        no->info = aux->info;

        no->dir =
            retira_no(no->dir, aux->info);
    }

    return no;
}

void abb_retira(ArvoreBusca *a, int v){
    if(a == NULL)
        return;

    a->raiz = retira_no(a->raiz, v);
}

static void libera_no(NoArvoreBusca *no){
    if(no == NULL)
        return;

    libera_no(no->esq);
    libera_no(no->dir);

    free(no);
}

void abb_libera(ArvoreBusca *a){
    if(a == NULL)
        return;

    libera_no(a->raiz);

    free(a);
}