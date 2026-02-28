#include <iostream>
#include <vector>

#include "sort.h"
#include "generateValues.h"
#include "toClock.h"

using namespace std;


// g++ -Iinclude main.cpp src/sorts/bubbleSort.cpp src/sorts/quickSort.cpp src/sorts/mergeSort.cpp src/utils/generateValues.cpp src/utils/toClock.cpp
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
    medirTempo(bubbleSort, valoresBubble, "BubbleSort");
    medirTempo(quickSort, valoresQuick, "QuickSort");
    medirTempo(mergeSort, valoresMerge, "MergeSort");
    
    cout << endl;

    // 100 valores
    medirTempo(bubbleSort, valoresBubble2, "BubbleSort");
    medirTempo(quickSort, valoresQuick2, "QuickSort");
    medirTempo(mergeSort, valoresMerge2, "MergeSort");

    cout << endl;
    
    // 1000 valores
    medirTempo(bubbleSort, valoresBubble3, "BubbleSort");
    medirTempo(quickSort, valoresQuick3, "QuickSort");
    medirTempo(mergeSort, valoresMerge3, "MergeSort");
    
    cout << endl;
    
    // 10000 valores
    medirTempo(bubbleSort, valoresBubble4, "BubbleSort");
    medirTempo(quickSort, valoresQuick4, "QuickSort");
    medirTempo(mergeSort, valoresMerge4, "MergeSort");

    cout << endl;

    // 100000 valores
    medirTempo(bubbleSort, valoresBubble5, "BubbleSort");
    medirTempo(quickSort, valoresQuick5, "QuickSort");
    medirTempo(mergeSort, valoresMerge5, "MergeSort");
}