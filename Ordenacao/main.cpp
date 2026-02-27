#include <iostream>
#include <vector>

using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void bubbleSort(vector<int> &lista);
void quickSort(vector<int> &lista, int a, int b);
#endif


int main() {
    vector<int> lista = {10, 17, 89, 43, 86, 12, 1, 100, -1, 4};
    int n = lista.size();

    // Metodo de ordenacao
    // bubbleSort(lista);
    quickSort(lista, 0, n - 1);

    cout << "Lista ordenada: " << endl;

    for (int i : lista)
    {
        cout << i << endl;
    }
}