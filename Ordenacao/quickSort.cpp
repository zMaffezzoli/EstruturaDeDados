#include <vector>

using namespace std;

void troca(vector<int> &lista, int a, int b){
    int temp = lista[a];
    lista[a] = lista[b];
    lista[b] = temp;
}

int particiona(vector<int> &lista, int a, int b){
    int x = lista[a]; // pivo temporario

    while (a < b){
        while (lista[a] < x){a++;} // Acha o maior valor depois do pivo
        while (lista[b] > x){b--;} // Acha o menor valor depois do pivo
        troca(lista, a, b);
    }
    return a;
}

void quickSort(vector<int> &lista, int a, int b){
    if (a < b){
        int indicePivo = particiona(lista, a, b);
        quickSort(lista, a, indicePivo - 1);
        quickSort(lista, indicePivo + 1, b);
    }
}