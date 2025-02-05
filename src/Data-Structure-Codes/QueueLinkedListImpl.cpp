#include <iostream>
#include <queue>
using namespace std;

// Node structure for Queue
class Node{
    public:
        int data;
        Node* next;
        
        // Constructor for Node class
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

// Queue class implementation
class Queue{
    Node* rear; 
    Node* front;
    
    public:
        // Constructor for Queue class
        Queue(){
            rear = NULL;
            front = NULL;
        }
        
        // Function to check if Queue is empty
        bool isempty(){
            return front == NULL;
        }
        
        // Enqueue function for Queue
        void enqueue(int element){
            Node* temp = new Node(element);
            
            if (isempty()){
                front = rear = temp;
                return;
            }
            
            rear->next = temp;
            rear = temp;
        }
        
        // Dequeue function for Queue
        void dequeue(){
            if (isempty()){
                cout << "Queue Underflow .." << endl;
                return;
            }
            
            Node* temp = front;
            front = front->next;
            
            if (front == NULL){
                rear = NULL;
            }
            
            delete temp;
        }
        
        // Function to get front value of Queue
        int getFront(){
            if (isempty()){
                cout << "Queue is Empty" << endl;
                return INT_MIN;
            }
            
            return front->data;
        }
        
        // Function to get rear value of Queue
        int getRear(){
            if (isempty()){
                cout << "Queue is Empty" << endl;
                return INT_MIN;
            }
            
            return rear->data;
        }
        
        // Function to print the Queue
        void getPrinted(){
            if (isempty()){
                cout << "The Queue is empty" << endl;
                return;
            }
            
            Node* temp = front;
            while (temp != NULL){
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
};

int main(){
    Queue H;
    H.enqueue(8);
    H.enqueue(99);
    cout << "The Queue is empty: " << H.isempty() << endl;
    H.dequeue();
    H.getPrinted();
    
    
    return 0;
}
