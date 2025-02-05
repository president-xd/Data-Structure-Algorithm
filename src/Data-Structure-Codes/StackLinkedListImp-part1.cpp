#include <iostream>
using namespace std;

// Node Structure for Stack
struct Node {
	int data;
	Node* next;
	
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

// Class for Function implementation of Stack
class Stack {
	private:
		Node* head;     // Pointer to the top node in the stack
		int stackSize;  // Capacity of the stack
		int top;      // Current number of elements in the stack
		
	public:
		Stack(int size) {
			this->head = NULL;
			this->stackSize = size;
			this->top = 0;
		}
		
		// Check if stack is empty
		bool isempty() {
			return head == NULL;
		}
				
		// Push a value onto the stack
		void push(int value) {
			if (top >= stackSize) {
				cout << "Stack Overflow.." << endl;
				return;
			}
			
			Node* temp = new Node(value);
			temp->next = head;
			head = temp;
			top++;
		}
		
		// Pop a value from the stack
		void pop() {
			if (isempty()) {
				cout << "The Stack is underflow.." << endl;
				return;
			}
			
			Node* temp = head;
			head = head->next;
			delete temp;
			top--;
		}
		
		// Peek at the top element of the stack
		void peek() {
			if (isempty()) {
				cout << "Stack Underflow.." << endl;
				return;
			}
			
			cout << "The top element of stack is : " << head->data << endl;
		}
		
		// Display the maximum capacity of the stack
		void maxSize() {
			cout << "Maximum capacity of stack is " << stackSize << endl;
		}
};

int main() {
	Stack A(3);
	A.push(99);
	A.push(42);
	A.push(17);
	A.push(100);  // This should trigger stack overflow
	A.peek();
	A.pop();
	A.peek();
	A.maxSize();
}
