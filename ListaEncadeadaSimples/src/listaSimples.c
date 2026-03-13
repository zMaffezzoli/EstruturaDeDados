#include "listaSimples.h"
#include <stdlib.h>
#include <stdio.h>

NoLista *sllCria(void){
    return NULL;
}

NoLista *sllInsere(NoLista *head, int v){

    NoLista *novo = (NoLista*) malloc(sizeof(NoLista)); // Aloca local de memoria e retorna o ponteiro do tipo NoLista

    novo->info = v;
    novo->prox = head;

    return novo;
}

void sllImprime(NoLista *head){
    while (head != NULL){
        printf("%d\n", head->info);
        head = head->prox;
    }
}

int sllVazia(NoLista *head){
    return head == NULL;
}

NoLista *sllBusca(NoLista *head, int v){
    while (head != NULL){
        if (head->info == v){
            return head;
        }

        head = head->prox;
    }

    return NULL;
}

int sllComprimento(NoLista *head){
    int comprimento = 0;
    
    while (head != NULL){
        comprimento++;
        head = head->prox;
    }

    return comprimento;
}

NoLista *sllUltimo(NoLista *head){
    if (head == NULL){
        return NULL;
    }

    while (head->prox != NULL){
        head = head->prox;
    }

    return head;
}

NoLista *sllRetira(NoLista *head, int v){
    
    // Lista vazia
    if (head == NULL){
        return NULL;
    }
    
    // Caso queremos retirar o primeiro no
    if (head->info == v){
        NoLista *temp = head;
        head = head->prox;
        free(temp); // Libera local de memoria do primeiro no que perdeu referencia
        return head;
    }
    
    // Remove no no meio, portanto nao altera o head inicial
    NoLista *p = head;

    // Vamos parar quando o proximo no eh o que queremos remover ou se o proximo eh null
    while (p->prox != NULL && p->prox->info != v){
        p = p->prox;
    }

    // Remove no do meio, entre 3 nos e verifica que nao e nulo
    if (p->prox != NULL){
        NoLista *temp = p->prox;
        p->prox = temp->prox;
        free(temp);
    }

    return head;
}

void sllLibera(NoLista *head){
    NoLista *p = head;

    // Passa um a um apagando e apontando para o prox
    while (p != NULL){
        NoLista *temp = p;
        p = p->prox;
        free(temp);
    }
}

NoLista *sllRetiraRecursivo(NoLista *head, int v){
    if (head == NULL){
        return NULL;
    } else if (head->info == v){
        NoLista *aux = head;
        head = head->prox;
        free(aux);

    } else{
        head->prox = sllRetiraRecursivo(head->prox, v);
    }

    return head;
}

void sllLiberaRecursivo(NoLista *head){
    if (head != NULL){
        NoLista *prox = head->prox;

        free(head);

        sllLiberaRecursivo(prox);
    }
}

NoLista *sllInsereFim(NoLista *head, int v){
    if(head->prox == NULL){
        NoLista *novo = (NoLista*) malloc(sizeof(NoLista));
        novo->info = v;
        head->prox = novo;
    } else{
        sllInsereFim(head->prox, v);
    }
    return head;
}

int sllIgual(NoLista *head1, NoLista *head2){
    while (head1 != NULL && head2 != NULL){
        if (head1->info != head2->info){
            return 0;
            
        }else{
            head1 = head1->prox;
            head2 = head2->prox;
        }
    }

    if (head1 == head2){ // Os dois devem chegar com o valor NULL
        return 1;
    }else{
        return 0;
    }
}

int sllIgualRecursivo(NoLista *head1, NoLista *head2){
    if (head1 == NULL && head2 == NULL){
        return 1;
    }

    else{
        if (head1 == NULL || head2 == NULL){
            return 0;
        }
        else{
            return ((head1->info == head2->info) && sllIgualRecursivo(head1->prox, head2->prox));
        }
    }
}

void sllImprimeRecursivo(NoLista *head){
    if (head != NULL){
        printf("%d\n", head->info);
        sllImprimeRecursivo(head->prox);
    }
}

int sllComprimentoRecursivo(NoLista *head){
    if (head == NULL){
        return 0;
    }

    return 1 + sllComprimentoRecursivo(head->prox);
}