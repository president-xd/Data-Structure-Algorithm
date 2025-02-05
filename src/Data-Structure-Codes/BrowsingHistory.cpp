#include <iostream>
#include <cmath>
#include <string>
#include <stack>
#include <vector>

using namespace std;

/*
• Add a new user record at a specified position.
• Delete a user record from a given position.
• Display the list of users in both forward and reverse order.
*/

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BorrowingHistory {
private:
    Node* head;
    Node* tail;

public:
    BorrowingHistory() {
        head = NULL;
        tail = NULL;
    }

    // Add a new user record at a specified position
    void addAtPosition(int data, int position) {
        Node* newNode = new Node(data);
        if (position == 0) {
            newNode->next = head;
            if (head != NULL) {
                head->prev = newNode;
            }
            head = newNode;
            if (tail == NULL) {
                tail = newNode;
            }
            return;
        }

        Node* temp = head;
        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }

        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;

        if (newNode->next == NULL) {
            tail = newNode;
        }
    }

    // Delete a user record from a given position
    void deleteAtPosition(int position) {
        if (head == NULL) return;

        Node* temp = head;

        if (position == 0) {
            head = temp->next;
            if (head != NULL) {
                head->prev = NULL;
            }
            delete temp;
            return;
        }

        for (int i = 0; temp != NULL && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == NULL || temp->next == NULL) {
            cout << "Position out of bounds" << endl;
            return;
        }

        Node* next = temp->next->next;
        delete temp->next;
        temp->next = next;

        if (next != NULL) {
            next->prev = temp;
        } else {
            tail = temp;
        }
    }

    // Display the list of users in forward order
    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Display the list of users in reverse order
    void displayReverse() {
        Node* temp = tail;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
};

int main() {
    BorrowingHistory history;

    // Adding user records
    history.addAtPosition(101, 0);
    history.addAtPosition(102, 1);
    history.addAtPosition(103, 2);
    history.addAtPosition(100, 0);

    // Display all user records in forward order
    cout << "User records (forward): ";
    history.displayForward();

    // Display all user records in reverse order
    cout << "User records (reverse): ";
    history.displayReverse();

    // Deleting a user record at position 2
    history.deleteAtPosition(2);

    // Display all user records in forward order after deletion
    cout << "User records after deletion (forward): ";
    history.displayForward();

    return 0;
}
