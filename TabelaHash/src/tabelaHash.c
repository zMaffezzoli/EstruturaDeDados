#include "tabelaHash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int hsh_hash(int matricula){
    return matricula % TAM;
}

TabelaHash *hsh_cria(void){
    TabelaHash *tab =
        (TabelaHash*) malloc(sizeof(TabelaHash));

    if(tab == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }

    int i;

    for(i = 0; i < TAM; i++){
        tab->vet[i] = NULL;
    }

    return tab;
}

Aluno *hsh_get(
    TabelaHash *tab,
    int matricula
){
    if(tab == NULL)
        return NULL;

    int indice =
        hsh_hash(matricula);

    Aluno *p =
        tab->vet[indice];

    while(p != NULL){

        if(p->matricula ==
           matricula)
            return p;

        p = p->prox;
    }

    return NULL;
}

Aluno *hsh_set(
    TabelaHash *tab,
    int matricula,
    char *nome,
    char *email,
    float mediaGeral
){
    if(tab == NULL)
        return NULL;

    Aluno *existe =
        hsh_get(tab, matricula);

    if(existe != NULL){

        strcpy(existe->nome, nome);
        strcpy(existe->email, email);
        existe->mediaGeral =
            mediaGeral;

        return existe;
    }

    Aluno *novo =
        (Aluno*) malloc(sizeof(Aluno));

    if(novo == NULL){
        printf("Erro de alocacao\n");
        exit(1);
    }

    novo->matricula =
        matricula;

    strcpy(novo->nome, nome);
    strcpy(novo->email, email);

    novo->mediaGeral =
        mediaGeral;

    int indice =
        hsh_hash(matricula);

    novo->prox =
        tab->vet[indice];

    tab->vet[indice] =
        novo;

    return novo;
}

void hsh_remove(
    TabelaHash *tab,
    int matricula
){
    if(tab == NULL)
        return;

    int indice =
        hsh_hash(matricula);

    Aluno *ant = NULL;
    Aluno *p =
        tab->vet[indice];

    while(p != NULL){

        if(p->matricula ==
           matricula){

            if(ant == NULL){
                tab->vet[indice] =
                    p->prox;
            }
            else{
                ant->prox =
                    p->prox;
            }

            free(p);
            return;
        }

        ant = p;
        p = p->prox;
    }
}

int hsh_contem(
    TabelaHash *tab,
    int matricula
){
    return hsh_get(
        tab,
        matricula
    ) != NULL;
}

int hsh_quantidade(
    TabelaHash *tab
){
    if(tab == NULL)
        return 0;

    int total = 0;

    int i;

    for(i = 0; i < TAM; i++){

        Aluno *p =
            tab->vet[i];

        while(p != NULL){
            total++;
            p = p->prox;
        }
    }

    return total;
}

int hsh_colisoes(
    TabelaHash *tab
){
    if(tab == NULL)
        return 0;

    int colisoes = 0;

    int i;

    for(i = 0; i < TAM; i++){

        int tamLista = 0;

        Aluno *p =
            tab->vet[i];

        while(p != NULL){
            tamLista++;
            p = p->prox;
        }

        if(tamLista > 1){
            colisoes +=
                tamLista - 1;
        }
    }

    return colisoes;
}

int hsh_maior_lista(
    TabelaHash *tab
){
    if(tab == NULL)
        return 0;

    int maior = 0;

    int i;

    for(i = 0; i < TAM; i++){

        int tamLista = 0;

        Aluno *p =
            tab->vet[i];

        while(p != NULL){
            tamLista++;
            p = p->prox;
        }

        if(tamLista > maior)
            maior = tamLista;
    }

    return maior;
}

void hsh_imprime(
    TabelaHash *tab
){
    if(tab == NULL)
        return;

    int i;

    for(i = 0; i < TAM; i++){

        if(tab->vet[i] == NULL)
            continue;

        printf("[%d]\n", i);

        Aluno *p =
            tab->vet[i];

        while(p != NULL){

            printf(
                "Matricula: %d\n",
                p->matricula
            );

            printf(
                "Nome: %s\n",
                p->nome
            );

            printf(
                "Email: %s\n",
                p->email
            );

            printf(
                "Media: %.2f\n\n",
                p->mediaGeral
            );

            p = p->prox;
        }
    }
}

void hsh_libera(
    TabelaHash *tab
){
    if(tab == NULL)
        return;

    int i;

    for(i = 0; i < TAM; i++){

        Aluno *p =
            tab->vet[i];

        while(p != NULL){

            Aluno *aux = p;

            p = p->prox;

            free(aux);
        }
    }

    free(tab);
}