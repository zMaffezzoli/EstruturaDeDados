#include "generateValues.h"

#include <random>
#include <vector>
#include <algorithm>

using namespace std;

// Funcao mais eficiente para geracao de numeros aleatorios
vector<int> geraValores(int n) {
    vector<int> valores;
    valores.reserve(n); // Ja reserva o local de memoria para o vetor

    // Popula o vetor com todos os numeros ordenados
    for (int i = 1; i <= n; i++){
        valores.push_back(i);
    }

     // Gera a seed
    random_device rd;
    mt19937 rng(rd());

    // Embaralha o vetor
    shuffle(valores.begin(), valores.end(), rng);

    return valores;
}