#include <iostream>
using namespace std;

// Swap function for swapping values
void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Merge Function to Merge the sorted Array
void merge(int Array[], int l, int mid, int r) {

    int size1 = mid - l + 1;
    int size2 = r - mid;

    int Array1[size1]; // Temp Array
    int Array2[size2]; // Temp Array

    // For Filling the Values in Array1
    for (int i = 0; i < size1; i++) {
        Array1[i] = Array[l + i];
    }

    // For Filling the Values in Array2
    for (int i = 0; i < size2; i++) {
        Array2[i] = Array[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = l; // Start at the leftmost index of the subarray

    while (i < size1 && j < size2) {
        if (Array1[i] <= Array2[j]) {
            Array[k] = Array1[i];
            i++;
        }
        else {
            Array[k] = Array2[j];
            j++;
        }
        k++;
    }

    // If i has reached to last position
    while (i < size1) {
        Array[k] = Array1[i];
        i++;
        k++;
    }

    // If j has reached to last position
    while (j < size2) {
        Array[k] = Array2[j];
        j++;
        k++;
    }
}

// Merge Sort Function to Sort the Elements
void mergeSort(int Array[], int l, int r) {

    if (l < r) {
        int mid = l + (r - l) / 2;
        mergeSort(Array, l, mid);
        mergeSort(Array, mid + 1, r);
        merge(Array, l, mid, r);
    }
}

// Function to print the Array
void print_Array(int Array[], int size) {

    cout << "The Elements of the Array are: " << endl;
    for (int i = 0; i < size; i++) {
        cout << Array[i] << " ";
    }
    cout << endl;
}

// Main Function
int main() {
    int Array[] = { 5, 2, 9, 1, 5, 6 };
    int size = sizeof(Array) / sizeof(Array[0]);

    cout << "Before Sorting: " << endl;
    print_Array(Array, size);

    mergeSort(Array, 0, size - 1);

    cout << "After Sorting: " << endl;
    print_Array(Array, size);

    return 0;
}
