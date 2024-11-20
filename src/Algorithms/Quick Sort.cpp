#include <iostream>
using namespace std;

// Swap function for swapping values
void swap(int Array[], int i, int j) {
    int temp = Array[i];
    Array[i] = Array[j];
    Array[j] = temp;
}

// Partition function: Divides the array into two parts around a pivot
int Partition(int Array[], int l, int r) {
    int pivot_position = Array[r]; // Select the last element as the pivot
    int i = l - 1;                // Index for the smaller element

    // Loop through the array and rearrange elements
    for (int j = l; j < r; j++) {
        if (Array[j] < pivot_position) { // If the current element is smaller than the pivot
            i++;                         // Increment the smaller element index
            swap(Array, i, j);           // Swap the smaller element with the current element
        }
    }

    // Place the pivot in its correct position
    swap(Array, i + 1, r);
    return i + 1; // Return the index of the pivot
}

// Quick Sort function: Recursively sorts the array
void Quick_Sort(int Array[], int l, int r) {
    if (l < r) { // Base condition: If the left index is less than the right index
        int pivot = Partition(Array, l, r); // Partition the array and get the pivot index

        // Recursively sort the subarrays on the left and right of the pivot
        Quick_Sort(Array, l, pivot - 1); // Sort the left subarray
        Quick_Sort(Array, pivot + 1, r); // Sort the right subarray
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

    Quick_Sort(Array, 0, size - 1);

    cout << "After Sorting: " << endl;
    print_Array(Array, size);

    return 0;
}
