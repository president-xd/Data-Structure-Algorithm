#include <iostream>
#include <vector>

using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                int temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;
            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }
            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }
            if (largest != index) {
                int temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int pop() {
        if (isEmpty()) {
            throw runtime_error("PriorityQueue is empty.");
        }
        int root = heap[0];

        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    int peek() {
        if (isEmpty()) {
            throw runtime_error("PriorityQueue is empty.");
        }
        return heap[0];
    }

    bool isEmpty() {
        return heap.empty();
    }
};

int main() {
    PriorityQueue pq;

    // Adding elements to the priority queue
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(40);

    // Displaying the top element
    cout << "Top element: " << pq.peek() << endl;

    // Removing elements from the priority queue
    cout << "Removed element: " << pq.pop() << endl;
    cout << "Removed element: " << pq.pop() << endl;

    // Displaying the top element after removal
    cout << "Top element after removal: " << pq.peek() << endl;

    return 0;
}
