#include <iostream>
#include <chrono>
#include <functional>
#include <vector>
#include <string>

using namespace std;
using namespace std::chrono;

void medirTempo(function<void (vector<int>&)> metodoOrdenamento, vector<int> &valores){
    auto inicio = high_resolution_clock::now();
    metodoOrdenamento(valores); // executa a função de ordenação
    auto fim = high_resolution_clock::now();

    auto duracao = duration_cast<microseconds>(fim - inicio).count();

    cout << "Tempo de execucao BubbleSort "  << valores.size() << " valores: " << duracao << " ms" << endl;
}

// "Sobrecarga" para os metodos Quick e Merge
void medirTempo(function<void (vector<int>&, int a, int b)> metodoOrdenamento, vector<int> &valores, int a, int b, string metodo){
    auto inicio = high_resolution_clock::now();
    metodoOrdenamento(valores, a, b); // executa a função de ordenação
    auto fim = high_resolution_clock::now();

    auto duracao = duration_cast<microseconds>(fim - inicio).count();

    cout << "Tempo de execucao " << metodo << " " << valores.size() << " valores: " << duracao << " ms" << endl;
}