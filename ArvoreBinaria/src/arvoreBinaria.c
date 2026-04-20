#include "arvoreBinaria.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ArvoreBinaria *ab_cria(void){
    ArvoreBinaria *arvore = (ArvoreBinaria*) malloc(sizeof(ArvoreBinaria));

    if (arvore == NULL){ 
        printf("Erro de alocação\n");
        exit(1);
    }

    arvore->raiz = NULL;
    return arvore;
}

NoArvoreBinaria *ab_cria_no(char *v, NoArvoreBinaria *sae, NoArvoreBinaria *sad){
    NoArvoreBinaria *no = (NoArvoreBinaria*) malloc(sizeof(NoArvoreBinaria));

    if (no == NULL){ 
        printf("Erro de alocação\n");
        exit(1);
    }

    no->sad = sad;
    no->sae = sae;
    strncpy(no->info, v, sizeof(no->info));
    no->info[sizeof(no->info)-1] = '\0';

    return no;
}

void ab_define_raiz(ArvoreBinaria *a, NoArvoreBinaria *r){
    if (a == NULL){
        printf("Árvore nula\n");
        exit(1);
    }

    a->raiz = r;
}

int ab_vazia(ArvoreBinaria *a){
    if (a == NULL){
        printf("Árvore inválida\n");
        exit(1);
    }

    return a->raiz == NULL;
}

static int pertence_no(NoArvoreBinaria *no, char *v){
    if (no == NULL) return 0;

    if (strcmp(no->info, v) == 0) return 1;

    return pertence_no(no->sae, v) || pertence_no(no->sad, v);
}

int ab_pertence(ArvoreBinaria *a, char *v){
    if (a == NULL) return 0;
    return pertence_no(a->raiz, v);
}

static int conta_folha(NoArvoreBinaria *no){
    if (no == NULL) return 0;

    if (no->sae == NULL && no->sad == NULL) return 1;

    return conta_folha(no->sae) + conta_folha(no->sad);
}

int ab_num_folhas(ArvoreBinaria *a){
    if (a == NULL) return 0;
    return conta_folha(a->raiz);
}

static int conta_no(NoArvoreBinaria *no){
    if (no == NULL) return 0;

    return 1 + conta_no(no->sae) + conta_no(no->sad);
}

int ab_num_nos(ArvoreBinaria *a){
    if (a == NULL) return 0;
    return conta_no(a->raiz);
}

static int altura_no(NoArvoreBinaria *no){
    if (no == NULL) return -1;

    int h_esq = altura_no(no->sae);
    int h_dir = altura_no(no->sad);

    return 1 + (h_esq > h_dir ? h_esq : h_dir);
}

int ab_altura(ArvoreBinaria *a){
    if (a == NULL) return -1;
    return altura_no(a->raiz);
}

static int igualdade_no(NoArvoreBinaria *no1, NoArvoreBinaria *no2){
    if (no1 == NULL && no2 == NULL) return 1;

    if (no1 == NULL || no2 == NULL) return 0;


    if (strcmp(no1->info, no2->info) != 0) return 0;

    return igualdade_no(no1->sae, no2->sae) && igualdade_no(no1->sad, no2->sad);
}

int ab_igual(ArvoreBinaria *a1, ArvoreBinaria *a2){
    if (a1 == NULL && a2 == NULL) return 1;

    if (a1 == NULL || a2 == NULL) return 0;

    return igualdade_no(a1->raiz, a2->raiz);
}

static void imprime_pre_no(NoArvoreBinaria *no){
    if (no == NULL){
        printf("<>");
        return;
    }

    printf("<%s", no->info);

    imprime_pre_no(no->sae);
    imprime_pre_no(no->sad);

    printf(">");
}

void ab_imprime_pre(ArvoreBinaria *a){
    if (a == NULL){
        printf("<>\n");
        return;
    }

    imprime_pre_no(a->raiz);
    printf("\n");
}

static void imprime_sim_no(NoArvoreBinaria *no){
    if (no == NULL){
        printf("<>");
        return;
    }

    printf("<");

    imprime_sim_no(no->sae);

    printf("%s", no->info);

    imprime_sim_no(no->sad);

    printf(">");
}

void ab_imprime_sim(ArvoreBinaria *a){
    if (a == NULL){
        printf("<>\n");
        return;
    }

    imprime_sim_no(a->raiz);
    printf("\n");
}

static void imprime_pos_no(NoArvoreBinaria *no){
    if (no == NULL){
        printf("<>");
        return;
    }

    printf("<");

    imprime_pos_no(no->sae);
    imprime_pos_no(no->sad);

    printf("%s", no->info);

    printf(">");
}

void ab_imprime_pos(ArvoreBinaria *a){
    if (a == NULL){
        printf("<>\n");
        return;
    }

    imprime_pos_no(a->raiz);
    printf("\n");
}

static void libera_no(NoArvoreBinaria *no){
    if (no == NULL) return;

    libera_no(no->sae);
    libera_no(no->sad);

    free(no);
}

void ab_libera(ArvoreBinaria *a){
    if (a == NULL) return;

    libera_no(a->raiz);
    a->raiz = NULL;
    free(a);
}