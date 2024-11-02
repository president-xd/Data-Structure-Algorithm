#include <iostream>
using namespace std;

// Swap function for swapping values
void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// Insertion Sort Function for Sorting an Array
void Insertion_Sort (int Array[], int n){
    
    for (int i = 0; i < n - 1; i++){
        int mini_idx = i;
        
        for (int j = i + 1; j < n; j++){
            if (Array[j] < Array[mini_idx]){
                mini_idx = j;
            }
        }
        Swap(Array[i], Array[mini_idx]);
    }
}

// Main Function
int main() {
    int Array[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(Array)/sizeof(Array[0]);
    
    Insertion_Sort(Array, size);
    
    for (int i = 0; i < size; i++){
        cout << " " << Array[i];
    }

    return 0;
}
