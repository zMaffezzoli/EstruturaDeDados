#include <iostream>
#include <vector>

using namespace std;

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
void bubbleSort(vector<int> &lista);
void quickSort(vector<int> &lista, int a, int b);
void mergeSort(vector<int> &lista, int inicial, int final);
vector<int> geraValores(int n);
#endif

// g++ teste.cpp generateValues.cpp bubbleSort.cpp quickSort.cpp mergeSort.cpp
int main() {
    // Valores gerados aleatoriamente
    vector<int> valoresBubble = geraValores(1000);
    vector<int> valoresQuick = valoresBubble;
    vector<int> valoresMerge = valoresBubble;

    // cout << "Antes do BubbleSort" << endl;
    
    // for (int i : valoresBubble){
    //     cout << i << endl;
    // }
    
    // bubbleSort(valoresBubble);

    // cout << "Depois do BubbleSort" << endl;
    // for (int i : valoresBubble){
    //     cout << i << endl;
    // }

    // cout << "Antes do Quick" << endl;
    
    // for (int i : valoresQuick){
    //     cout << i << endl;
    // }
    
    // quickSort(valoresQuick, 0, valoresQuick.size() - 1);

    // cout << "Depois do QuickSort" << endl;
    // for (int i : valoresQuick){
    //     cout << i << endl;
    // }

    cout << "Antes do MergeSort" << endl;
    
    for (int i : valoresMerge){
        cout << i << endl;
    }
    
    mergeSort(valoresMerge, 0, valoresMerge.size() - 1);

    cout << "Depois do MergeSort" << endl;
    for (int i : valoresMerge){
        cout << i << endl;
    }
}