#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a single linked list with one node
Node* createLinkedList() {
    Node* head = new Node();
    head->data = 10;
    head->next = NULL;
    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* intersectLists(Node* L1, Node* L2) {
    Node* result = NULL; // Intersection list head
    Node* tail = NULL;

    while (L1 != NULL && L2 != NULL) {
        if (L1->data == L2->data) {
            Node* newNode = new Node();
            newNode->data = L1->data;
            newNode->next = NULL;
            if (result == NULL) {
                result = newNode;  // First element in result list
                tail = result;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            L1 = L1->next;
            L2 = L2->next;
        } else if (L1->data < L2->data) {
            L1 = L1->next;
        } else {
            L2 = L2->next;
        }
    }
    return result;
}

// Add a node at the beginning
void addAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Add a node at the end
void addAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Add a node in the middle after a given position
void addInMiddle(Node* prevNode, int value) {
    if (prevNode == NULL) {
        cout << "Previous node cannot be NULL";
        return;
    }
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void removeNode(Node*& head, int value) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == value) {
        head = temp->next; 
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    delete temp;
}

void reverseList(Node*& head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev to current
        current = next;        // Move current to next
    }
    head = prev;  // Update head to the new first node
}

int main() {
    Node* L1 = createLinkedList();

	addAtBeginning(L1, 89);
	printList(L1);
	
	removeNode(L1, 10);
    
    printList(L1);
    
    return 0;
}
