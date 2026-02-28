#include <iostream>
#include <vector>

#include "sort.h"
#include "generateValues.h"

using namespace std;

// g++ test.cpp generateValues.cpp bubbleSort.cpp quickSort.cpp mergeSort.cpp
int main() {
    // Valores gerados aleatoriamente
    vector<int> valoresBubble = geraValores(1000);
    vector<int> valoresQuick = valoresBubble;
    vector<int> valoresMerge = valoresBubble;

    cout << endl << "Antes do ordenamento" << endl;
    
    for (int i : valoresBubble){
        cout << i << ", ";
    }
    
    bubbleSort(valoresBubble);

    cout << endl << "BubbleSort" << endl;
    for (int i : valoresBubble){
        cout << i << ", ";
    }

    quickSort(valoresQuick);

    cout << endl << "QuickSort" << endl;
    for (int i : valoresQuick){
        cout << i << ", ";
    }
    
    mergeSort(valoresMerge);

    cout << endl << "MergeSort" << endl;

    for (int i : valoresMerge){
        cout << i << ", ";
    }
}