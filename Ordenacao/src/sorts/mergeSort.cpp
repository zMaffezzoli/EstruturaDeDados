#include "sort.h"

#include <vector>
#include <limits>

using namespace std;

static void merge(vector<int> &lista, int inicial, int meio, int final){
    int qtd_listaL = meio - inicial + 1;
    int qtd_listaR = final - meio;

    vector<int> listaL(qtd_listaL + 1); // Adiciona um index a mais para a const inf
    vector<int> listaR(qtd_listaR + 1);

    // Vetores copias para o processo
    for (int i = 0; i < qtd_listaL; i++){
        listaL[i] = lista[inicial + i];
    }

    for (int j = 0; j < qtd_listaR; j++){
        listaR[j] = lista[meio + j + 1];
    }

    listaL[qtd_listaL] = numeric_limits<int>::max();
    listaR[qtd_listaR] = numeric_limits<int>::max();  

    int i = 0, j = 0;

    for (int k = inicial; k <= final; k++){
        if (listaL[i] <= listaR[j]){
            lista[k] = listaL[i];
            i++;
        }else{
            lista[k] = listaR[j];
            j++;
        }
    }
}

static void mergeSortRec(vector<int> &lista, int inicial, int final){
    if (inicial < final){
        int meio = inicial + (final - inicial) / 2; // Evita overflow
        mergeSortRec(lista, inicial, meio);
        mergeSortRec(lista, meio + 1, final);
        merge(lista, inicial, meio, final);
    }
}

void mergeSort(vector<int>& lista) {
    if (!lista.empty()) {
        mergeSortRec(lista, 0, lista.size() - 1);
    }
}