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

class CustomerServiceQueue {
private:
    Node* front;
    Node* rear;

public:
    CustomerServiceQueue() {
        front = NULL;
        rear = NULL;
    }

    // Add a customer to the queue
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

    // Remove a customer from the queue
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

    // Display all customers in the queue
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
    CustomerServiceQueue queue;

    // Adding customers to the queue
    queue.enqueue("Alice");
    queue.enqueue("Bob");
    queue.enqueue("Charlie");

    // Display all customers in the queue
    cout << "Customer queue: ";
    queue.display();

    // Removing a customer from the queue
    queue.dequeue();

    // Display all customers in the queue after dequeue
    cout << "Customer queue after dequeue: ";
    queue.display();

    return 0;
}
