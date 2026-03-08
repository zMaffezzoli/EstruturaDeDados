#include "listaSimples.h"
#include <stdio.h>

int main(){
    NoLista *lista = sllCria();

    lista = sllInsere(lista, 3);
    lista = sllInsere(lista, 2);
    lista = sllInsere(lista, 1);
    
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

    // Testa retirar um elemento em diferentes posicoes
    // NoLista *retirar = sllRetira(lista, 2);
    // sllImprime(retirar);

    // NoLista *retirar = sllRetira(lista, 1);
    // sllImprime(retirar);

    // NoLista *retirar = sllRetira(lista, 3);
    // sllImprime(retirar);

    // Recebe o head caso nao ache o elemento
    NoLista *retirar = sllRetira(lista, 4);
    sllImprime(retirar);

    sllLibera(lista);
    lista = NULL; // Comente e veja que dará erro, pois a lista já não existe
    
    printf("Comprimento da lista: %d\n", sllComprimento(lista));
    return 0;
}