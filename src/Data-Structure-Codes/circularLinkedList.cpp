#include <iostream>
using namespace std;

// Structure Circular Node
struct Node {
    int data;
    Node* next;
};

// Function to count Nodes in List
int countNodes(Node* List) {
    if (List == NULL) {
        cout << "The List is empty.." << endl;
        return 0;
    }
    Node* current = List;
    int count = 0;

    do {
        count++;
        current = current->next;
    } while (current != List);

    return count;
}

// Function to insert Node at Head
void insertAtHead(Node*& List, int data) {
    Node* temp = new Node;
    Node* current = List;

    if (List == NULL) {
        temp->data = data;
        temp->next = temp;
        List = temp;
        return;
    }

    temp->data = data;
    while (current->next != List) {
        current = current->next;
    }
    current->next = temp;
    temp->next = List;
    List = temp;
}

// Function to Add Node at Last
void insertAtEnd(Node*& List, int data) {
    if (List == NULL) {
        insertAtHead(List, data);
        return;
    }

    Node* temp = new Node;
    Node* current = List;

    temp->data = data;

    while (current->next != List) {
        current = current->next;
    }
    current->next = temp;
    temp->next = List;
}

// Function to Add Node at Middle
void insertAtMiddle(Node*& List, int data, int position) {
    if (List == NULL || position <= 1) {
        insertAtHead(List, data);
        return;
    }

    Node* temp = new Node;
    temp->data = data;
    int count = 1;
    Node* current = List;
    while (count < position - 1 && current->next != List) {
        current = current->next;
        count++;
    }

    if (count < position - 1) {
        cout << "Position out of range.." << endl;
        delete temp;
        return;
    }

    temp->next = current->next;
    current->next = temp;
}

// Function to delete Head Node
void deleteHeadNode(Node*& List) {
    if (List == NULL) {
        cout << "Empty List..." << endl;
        return;
    }

    Node* temp = List;
    if (List->next == List) {
        List = NULL;
    }
    else {
        Node* current = List;
        while (current->next != List) {
            current = current->next;
        }
        current->next = List->next;
        List = List->next;
    }
    delete temp;
}

// Function to delete Last Node
void deleteLastNode(Node*& List) {
    if (List == NULL) {
        cout << "Empty List..." << endl;
        return;
    }

    if (List->next == List) {
        delete List;
        List = NULL;
        return;
    }

    Node* current = List;
    while (current->next->next != List) {
        current = current->next;
    }

    delete current->next;
    current->next = List;
}

// Function to delete Middle Node
void deleteMiddleNode(Node*& List, int position) {
    if (position <= 0) {
        cout << "Position out of range.." << endl;
        return;
    }

    if (List == NULL) {
        cout << "No Node to Delete.." << endl;
        return;
    }

    if (position == 1) {
        deleteHeadNode(List);
        return;
    }

    int count = 1;
    Node* current = List;
    while (count < position - 1 && current->next != List) {
        current = current->next;
        count++;
    }

    if (current->next == List || current->next->next == List) {
        cout << "Position out of range.." << endl;
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

// Function to Print the List
void getPrinted(Node* List) {
    if (List == NULL) {
        cout << "The List is empty." << endl;
        return;
    }

    Node* temp = List;
    do {
        cout << "-----------------------------------------------" << endl;
        cout << "The current Address : " << temp << endl;
        cout << "The Data : " << temp->data << endl;
        cout << "The next Address : " << temp->next << endl;
        cout << "-----------------------------------------------" << endl;
        temp = temp->next;
    } while (temp != List);
}

int main() {
    Node* List = NULL;

    insertAtHead(List, 1); // 1
    insertAtHead(List, 3); // 3, 1
    insertAtEnd(List, 8);  // 3, 1, 8
    insertAtMiddle(List, 7, 2); // 3, 7, 1, 8
    deleteHeadNode(List); // 7, 1, 8
    deleteLastNode(List); // 7, 1
    deleteMiddleNode(List, 1); // 1
    getPrinted(List);

    return 0;
}
