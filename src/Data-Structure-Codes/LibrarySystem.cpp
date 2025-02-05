#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

/*
+ Allows adding a new book record at the beginning and end of the collection.
• Supports deleting a book record from a specified position.
• Can display all book records efficiently.
*/

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class BookCollection {
private:
    Node* head;
    Node* tail;

public:
    BookCollection() {
        head = NULL;
        tail = NULL;
    }

    // Add a book record at the beginning
    void addAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Add a book record at the end
    void addAtEnd(int data) {
        Node* newNode = new Node(data);
        if (tail == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Delete a book record from a specified position
    void deleteAtPosition(int position) {
        if (head == NULL) return;

        Node* temp = head;

        if (position == 0) {
            head = temp->next;
            delete temp;
            return;
        }

        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) return;

        Node* next = temp->next->next;
        delete temp->next;
        temp->next = next;
    }

    // Display all book records
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    BookCollection collection;

    // Adding book records
    collection.addAtBeginning(101);
    collection.addAtEnd(102);
    collection.addAtEnd(103);
    collection.addAtBeginning(100);

    // Display all book records
    cout << "Book records: ";
    collection.display();

    // Deleting a book record at position 2
    collection.deleteAtPosition(2);

    // Display all book records after deletion
    cout << "Book records after deletion: ";
    collection.display();

    return 0;
}
