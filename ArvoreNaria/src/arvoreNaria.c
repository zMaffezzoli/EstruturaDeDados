#include "arvoreNaria.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ArvoreNaria *an_cria(void){
    ArvoreNaria *arvore = (ArvoreNaria*) malloc(sizeof(ArvoreNaria));

    if (arvore == NULL){ 
        printf("Erro de alocação\n");
        exit(1);
    }

    arvore->raiz = NULL;

    return arvore;
}

NoArvoreNaria *an_cria_no(char *v){
    NoArvoreNaria *no = (NoArvoreNaria*) malloc(sizeof(NoArvoreNaria));

    if (no == NULL){ 
        printf("Erro de alocação\n");
        exit(1);
    }

    strncpy(no->info, v, sizeof(no->info));
    no->info[sizeof(no->info)-1] = '\0';
    
    no->prim = NULL;
    no->prox = NULL;

    return no;
}

void an_define_raiz(ArvoreNaria *a, NoArvoreNaria *r){
    if (a == NULL){
        printf("Árvore nula\n");
        exit(1);
    }

    a->raiz = r;
}

void an_insere_filho(NoArvoreNaria *pai, NoArvoreNaria *filho){
    filho->prox = pai->prim;
    pai->prim = filho;
}


int an_vazia(ArvoreNaria *a){
    return (a == NULL || a->raiz == NULL);
}

static int pertence_no(NoArvoreNaria *no, char *v){
    if (no == NULL) return 0;


    if (strcmp(no->info, v) == 0) return 1;

    return pertence_no(no->prim, v) || pertence_no(no->prox, v);
}

int an_pertence(ArvoreNaria *a, char *v){
    if (a == NULL) return 0;

    return pertence_no(a->raiz, v);
}

static int conta_nos(NoArvoreNaria *no){
    if (no == NULL) return 0;

    return 1 + conta_nos(no->prim) + conta_nos(no->prox);
}

int an_num_nos(ArvoreNaria *a){
    if (a == NULL) return 0;

    return conta_nos(a->raiz);
}

static int conta_folhas(NoArvoreNaria *no){
    if (no == NULL) return 0;

    int atual = 0;

    if (no->prim == NULL) atual = 1;

    return atual + conta_folhas(no->prim) + conta_folhas(no->prox);
}

int an_folhas(ArvoreNaria *a){
    if (a == NULL) return 0;

    return conta_folhas(a->raiz);
}

static int altura_no(NoArvoreNaria *no){
    if (no == NULL) return -1;

    int hmax = -1;

    NoArvoreNaria *filho = no->prim;

    while (filho != NULL){
        int h = altura_no(filho);

        if (h > hmax){
            hmax = h;
        }

        filho = filho->prox;
    }

    return hmax + 1;
}

int an_altura(ArvoreNaria *a){
    if (a == NULL) return -1;

    return altura_no(a->raiz);
}

static int igualdade_no(NoArvoreNaria *n1, NoArvoreNaria *n2){
    if (n1 == NULL && n2 == NULL) return 1;

    if (n1 == NULL || n2 == NULL) return 0;

    if (strcmp(n1->info, n2->info) != 0) return 0;

    return igualdade_no(n1->prim, n2->prim) && igualdade_no(n1->prox, n2->prox);
}

int an_igual(ArvoreNaria *a1, ArvoreNaria *a2){
    if (a1 == NULL && a2 == NULL) return 1;

    if (a1 == NULL || a2 == NULL) return 0;

    return igualdade_no(a1->raiz, a2->raiz);
}

static void imprime_no(NoArvoreNaria *no){
    if (no == NULL) return;

    printf("<%s", no->info);

    NoArvoreNaria *filho = no->prim;

    while (filho != NULL){
        printf(" ");

        imprime_no(filho);

        filho = filho->prox;
    }

    printf(">");
}

void an_imprime(ArvoreNaria *a){
    if (a == NULL || a->raiz == NULL){
        printf("<>\n");
        return;
    }

    imprime_no(a->raiz);
    printf("\n");
}

static void libera_no(NoArvoreNaria *no){
    if (no == NULL) return;

    libera_no(no->prim);
    libera_no(no->prox);

    free(no);
}

void an_libera(ArvoreNaria *a){
    if (a == NULL) return;

    libera_no(a->raiz);

    a->raiz = NULL;

    free(a);
}