#include <iostream>
#include <cmath>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void push(Node* &head, int element){
	Node* temp = new Node;
	
	if (head->next == NULL){
		temp->data = element;
		temp->next = NULL;
		head = temp;
		return;
	}
	
	temp->data = element;
	temp->next = head;
	head = temp;
}

void pop(Node* &head){
	Node* temp = head;
	if (head->next == NULL){
		return;
	}
	head = head->next;
	delete temp;
}

void peek(Node* &head){
	if (head != NULL){
		cout << " " << head->data << endl;
		return;
	} else {
		cout << "The Stack is empty.." << endl;
		return;
	}
}

int main(){
	
	// Fill Main Function According to your need
	
	
	return 0;
}
