#include <iostream>
using namespace std;

class Queue{
    public:
    int front;
    int rear;
    int size;
    int* Array;
    Queue(int size){
        this->size = size;
        this->rear = 0;
        this->front = 0;
        this->Array = new int[size];
    }
    
    void enqueue(int element){
        if (size - 1 == rear){
            cout << "Queue Overflow.." << endl;
        }
        else {
            Array[rear] = element;
            rear++;
            cout << "ENqueued : " << element << endl;
        }
    }
    
    void dequeue(){
        
        if (front<0){
            cout << "Queue is empty.." << endl;
        } else {
            cout << "Dequeued : " << Array[front] << endl;
            front++;
            
        }
    }
    
    void isempty(){
        if (front == -1 && rear == 0){
            cout << "The queue is empty.." << endl;
        } else {
            cout << "The queue is not empty.." << endl;
        }
    }
    
    void peek(){
        if (front == -1 && rear == 0){
            cout << "The queue is empty.." << endl;
            
        } else {
            cout << Array[rear - 1] << " " << endl;
        }
    }
    
};

int main() {
    
    Queue A(8);
    A.enqueue(10);
    A.peek();
    A.enqueue(11);
    A.dequeue();
    // 
	A.peek();
	
    
    return 0;
}
