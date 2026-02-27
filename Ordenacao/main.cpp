#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void bubbleSort(vector<int> &lista);
void quickSort(vector<int> &lista, int a, int b);
void mergeSort(vector<int> &lista, int inicial, int final);
vector<int> geraValores(int n);
void medirTempo(function<void (vector<int>&)> metodoOrdenamento, vector<int> &valores);
void medirTempo(function<void (vector<int>&, int a, int b)> metodoOrdenamento, vector<int> &valores, int a, int b, string metodo);
#endif

// g++ main.cpp generateValues.cpp bubbleSort.cpp quickSort.cpp mergeSort.cpp calculateTime.cpp
int main() {
    // Valores gerados aleatoriamente
    vector<int> valoresBubble = geraValores(10);
    vector<int> valoresBubble2 = geraValores(100);
    vector<int> valoresBubble3 = geraValores(1000);
    vector<int> valoresBubble4 = geraValores(10000);
    vector<int> valoresBubble5 = geraValores(100000);

    // Copias para quick e merge sort
    vector<int> valoresQuick = valoresBubble;
    vector<int> valoresQuick2 = valoresBubble2;
    vector<int> valoresQuick3 = valoresBubble3;
    vector<int> valoresQuick4 = valoresBubble4;
    vector<int> valoresQuick5 = valoresBubble5;

    vector<int> valoresMerge = valoresBubble;
    vector<int> valoresMerge2 = valoresBubble2;
    vector<int> valoresMerge3 = valoresBubble3;
    vector<int> valoresMerge4 = valoresBubble4;
    vector<int> valoresMerge5 = valoresBubble5;
    
    // 10 valores
    medirTempo(bubbleSort, valoresBubble);
    medirTempo(quickSort, valoresQuick, 0, valoresQuick.size() - 1, "QuickSort");
    medirTempo(mergeSort, valoresMerge, 0, valoresMerge.size() - 1, "MergeSort");
    
    cout << endl;

    // 100 valores
    medirTempo(bubbleSort, valoresBubble2);
    medirTempo(quickSort, valoresQuick2, 0, valoresQuick2.size() - 1, "QuickSort");
    medirTempo(mergeSort, valoresMerge2, 0, valoresMerge2.size() - 1, "MergeSort");

    cout << endl;
    
    // 1000 valores
    medirTempo(bubbleSort, valoresBubble3);
    medirTempo(quickSort, valoresQuick3, 0, valoresQuick3.size() - 1, "QuickSort");
    medirTempo(mergeSort, valoresMerge3, 0, valoresMerge3.size() - 1, "MergeSort");
    
    cout << endl;
    
    // 10000 valores
    medirTempo(bubbleSort, valoresBubble4);
    medirTempo(quickSort, valoresQuick4, 0, valoresQuick4.size() - 1, "QuickSort");
    medirTempo(mergeSort, valoresMerge4, 0, valoresMerge4.size() - 1, "MergeSort");

    cout << endl;

    // 100000 valores
    medirTempo(bubbleSort, valoresBubble5);
    medirTempo(quickSort, valoresQuick5, 0, valoresQuick5.size() - 1, "QuickSort");
    medirTempo(mergeSort, valoresMerge5, 0, valoresMerge5.size() - 1, "MergeSort");
}