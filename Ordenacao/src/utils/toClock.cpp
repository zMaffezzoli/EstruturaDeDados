#include "toClock.h"

#include <iostream>
#include <chrono>
#include <functional>
#include <vector>
#include <string>

using namespace std;
using namespace std::chrono;


void medirTempo(function<void (vector<int>&)> metodoOrdenamento, vector<int> &valores, const string& metodo){
    auto inicio = high_resolution_clock::now();
    metodoOrdenamento(valores); // executa a função de ordenação
    auto fim = high_resolution_clock::now();

    auto duracao = duration_cast<nanoseconds>(fim - inicio).count();

    cout << "Tempo de execucao " << metodo << " com " << valores.size() << " valores: " << duracao << " ns" << endl;
}