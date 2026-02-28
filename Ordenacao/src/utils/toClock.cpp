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

    auto duracaoNs = duration_cast<nanoseconds>(fim - inicio).count();
    auto duracaoMs = duration_cast<milliseconds>(fim - inicio).count();
    // ≈ em UTF-8 = 0xE2 0x89 0x88

    cout << "Tempo de execucao " << metodo << " com " << valores.size() << " valores: " << duracaoNs << "ns \xE2\x89\x88 " << duracaoMs << "ms" << endl;
}