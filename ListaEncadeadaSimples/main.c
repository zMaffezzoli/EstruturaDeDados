#include "listaSimples.h"
#include <stdio.h>

// gcc -Iinclude main.c src/listaSimples.c -o list.out && ./list.out
int main(){
    NoLista *lista = sllCria();
    NoLista *lista2 = sllCria();

    lista = sllInsere(lista, 3);
    lista = sllInsere(lista, 2);
    lista = sllInsere(lista, 1);
    lista = sllInsereFim(lista, 4);
    
    lista2 = sllInsere(lista2, 1);
    lista2 = sllInsereFim(lista2, 2);
    lista2 = sllInsereFim(lista2, 3);
    lista2 = sllInsereFim(lista2, 4);

    printf("As duas listas são iguais (Recursivo)? %d\n", sllIgualRecursivo(lista, lista2));
    printf("As duas listas são iguais? %d\n", sllIgualRecursivo(lista, lista2));

    sllImprimeRecursivo(lista);

    printf("Está vazia: %d\n", sllVazia(lista));

    NoLista *res = sllBusca(lista, 3);

    if (res != NULL){
        printf("Encontrado: %d\n", res->info);
    }else{
        printf("Valor nao encontrado\n");
    }
    
    printf("Comprimento da lista (Recursivo): %d\n", sllComprimentoRecursivo(lista));
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