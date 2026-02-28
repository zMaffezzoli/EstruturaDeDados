#include "sort.h"

#include <vector>

using namespace std;

static void troca(vector<int> &lista, int a, int b){
    int temp = lista[a];
    lista[a] = lista[b];
    lista[b] = temp;
}

static int particiona(vector<int> &lista, int a, int b){
    int pivot = lista[b]; 
    int i = a - 1;

    for (int j = a; j < b; j++) {
        if (lista[j] <= pivot) {
            i++;
            troca(lista, i, j);
        }
    }

    troca(lista, i + 1, b);
    return i + 1;
}

static void quickSortRec(vector<int> &lista, int a, int b){
    if (a < b){
        int indicePivo = particiona(lista, a, b);
        quickSortRec(lista, a, indicePivo - 1);
        quickSortRec(lista, indicePivo + 1, b);
    }
}

void quickSort(vector<int>& lista) {
    if (!lista.empty()) {
        quickSortRec(lista, 0, lista.size() - 1);
    }
}