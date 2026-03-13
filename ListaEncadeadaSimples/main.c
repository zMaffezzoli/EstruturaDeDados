#include "listaSimples.h"
#include <stdio.h>

int main(){
    NoLista *lista = sllCria();

    lista = sllInsere(lista, 3);
    lista = sllInsere(lista, 2);
    lista = sllInsere(lista, 1);
    lista = sllInsereFim(lista, 4);
    
    sllImprime(lista);

    printf("Está vazia: %d\n", sllVazia(lista));

    NoLista *res = sllBusca(lista, 3);

    if (res != NULL){
        printf("Encontrado: %d\n", res->info);
    }else{
        printf("Valor nao encontrado\n");
    }
    
    printf("Comprimento da lista: %d\n", sllComprimento(lista));
    
    NoLista *ultimo = sllUltimo(lista);

    if (ultimo != NULL){
        printf("Ultimo elemento da lista: %d\n", ultimo->info);
    }else{
        printf("Lista vazia\n");
    }

    // Testa retirar um elemento em diferentes posicoes (Descomente as linhas e teste cada um)
    // lista = sllRetira(lista, 2);
    // sllImprime(lista);

    // lista = sllRetira(lista, 1);
    // sllImprime(lista);

    lista = sllRetiraRecursivo(lista, 3);
    sllImprime(lista);

    // Recebe o head caso nao ache o elemento
    // lista = sllRetira(lista, 4);
    // sllImprime(lista);

    sllLiberaRecursivo(lista);
    lista = NULL; // Comente e veja que dará erro, pois a lista já não existe
    
    printf("Comprimento da lista: %d\n", sllComprimento(lista));
    return 0;
}