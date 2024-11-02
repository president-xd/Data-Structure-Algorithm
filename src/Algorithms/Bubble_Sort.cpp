#include <iostream>
using namespace std;

// Swap Function to Swap values
void Swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

// Function of the Bubble Sort Algorithm
void BubbleSort(int Array[], int n){
    
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (Array[j] > Array[j + 1]){
                Swap(Array[j], Array[j + 1];
            }
        }
    }
}

// Main Function
int main() {
    int Array[] = {5, 2, 9, 1, 5, 6};
    int size = sizeof(Array)/sizeof(Array[0]);
    
    BubbleSort(Array, size);
    
    for (int i = 0; i < size; i++){
        cout << " " << Array[i];
    }

    return 0;
}
