#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string data) {
        this->next = NULL;
        this->data = data;
    }
};

class VIPCustomerQueue {
private:
    Node* front;
    Node* rear;

public:
    VIPCustomerQueue() {
        front = NULL;
        rear = NULL;
    }

    // Add a VIP customer to the queue
    void enqueue(string data) {
        Node* newNode = new Node(data);
        if (rear == NULL) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Remove a VIP customer from the queue
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL) {
            rear = NULL;
        }
        delete temp;
    }

    // Display all VIP customers in the queue
    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    VIPCustomerQueue queue;

    // Adding VIP customers to the queue
    queue.enqueue("Alice");
    queue.enqueue("Bob");
    queue.enqueue("Charlie");

    // Display all VIP customers in the queue
    cout << "VIP Customer queue: ";
    queue.display();

    // Removing a VIP customer from the queue
    queue.dequeue();

    // Display all VIP customers in the queue after dequeue
    cout << "VIP Customer queue after dequeue: ";
    queue.display();

    return 0;
}
