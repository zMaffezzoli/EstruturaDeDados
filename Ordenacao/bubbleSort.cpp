#include <vector>

using namespace std;

void bubbleSort(vector<int> &lista){
    int n = lista.size();
    
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (lista[j] > lista[j + 1]){
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}