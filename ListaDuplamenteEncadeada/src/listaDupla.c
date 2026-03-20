#include "listaDupla.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

NoListaDupla *dllCria(void){
    return NULL;
}

NoListaDupla *dllInsere(NoListaDupla *head, char *v){
    NoListaDupla *novo = (NoListaDupla*) malloc(sizeof(NoListaDupla)); // Aloca local de memoria e retorna o ponteiro do tipo NoLista

    strcpy(novo->info, v); // Recebe a string do parametro
    
    novo->prox = head;
    novo->ant = NULL;

    if (head != NULL){
        head->ant = novo;
    }

    return novo;
}

void dllImprime(NoListaDupla *head){
    int i = 1;
    while (head != NULL){
        printf("%d. %s\n", i, head->info);
        i++;
        head = head->prox;
    }
}

int dllVazia(NoListaDupla *head){
    return head == NULL;
}

NoListaDupla *dllBusca(NoListaDupla *head, char *v){
    while (head != NULL){
            if (strcmp(head->info, v) == 0){
                return head;
            }

            head = head->prox;
        }

        return NULL;
}

int dllComprimento(NoListaDupla *head){
    int comprimento = 0;
    
    while (head != NULL){
        comprimento++;
        head = head->prox;
    }

    return comprimento;
}

NoListaDupla *dllUltimo(NoListaDupla *head){
    if (head == NULL){
        return NULL;
    }

    while (head->prox != NULL){
        head = head->prox;
    }

    return head;
}

NoListaDupla *dllRetira(NoListaDupla *head, char *v){
    NoListaDupla *busca = dllBusca(head, v);

    if (busca != NULL){
        if (busca->ant == NULL){ // Caso em que o no que queremos remover e o primeiro 
            NoListaDupla *temp = busca;
            
            head = busca->prox;
            head->ant = NULL;

            free(temp);
        }

        else if (busca->prox == NULL){  // Caso em que o no que queremos remover e o ultimo
            NoListaDupla *temp = busca;
            busca->ant->prox = NULL;
            free(temp);
        }

        // Caso em que o no que queremos retirar e um no no meio da lista
        else{
            NoListaDupla *temp = busca;
            busca->ant->prox = busca->prox;
            busca->prox->ant = busca->ant;
            
            free(temp);
        }


        return head;
    }
    
    return NULL;
}

void dllLibera(NoListaDupla *head){
    NoListaDupla *p = head;

    // Passa um a um apagando e apontando para o prox
    while (p != NULL){
        NoListaDupla *temp = p;
        p = p->prox;
        free(temp);
    }
}

NoListaDupla *dllInsereFim(NoListaDupla *head, char *v){
    if(head->prox == NULL){
        NoListaDupla *novo = (NoListaDupla*) malloc(sizeof(NoListaDupla));
        strcpy(novo->info, v);
        head->prox = novo;
        novo->ant = head;
    } else{
        dllInsereFim(head->prox, v);
    }
    return head;
}

NoListaDupla *dllInserePosicao(NoListaDupla *head, char *v, int posicao){
    int i = 1;
    NoListaDupla *temp = head;
    
    // Se eu adicionar uma posicao negativa ou a primeira, adiciona no inicio
    if (posicao <= 1){
        head = dllInsere(head, v);
        return head;
    }
    // Percorre até achar a posicao
    while (i != posicao){
        if (temp->prox != NULL){
            temp = temp->prox;
            i++;
        }
        else { 
            if (posicao > dllComprimento(head)){
                printf("Intervalo inválido!\nNão é possível adicionar música \"%s\" na posição %dº. Insira no fim da playlist \n", v, posicao); // Se eu inserir uma posicao maior que a lista contem
                return head;
            }else{
            
                head = dllInsereFim(head, v);
                return head;
            }
        } 
    }
    
    // Caso nosso no nao seja inserido no inicio ou no fim
    NoListaDupla *novo = (NoListaDupla*) malloc(sizeof(NoListaDupla));
    strcpy(novo->info, v);
    
    novo->prox = temp;
    novo->ant = temp->ant;
    temp->ant->prox = novo;
    temp->ant = novo;
    
    return head;
}