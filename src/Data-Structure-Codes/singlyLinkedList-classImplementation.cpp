#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() : head(NULL) {}

    void insert_at_head(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }

    void insert_at_tail(int data) {
        Node* new_node = new Node(data);
        if (!head) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void delete_node(int data) {
        if (!head) return;
        if (head->data == data) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != data) {
            temp = temp->next;
        }
        if (temp->next) {
            Node* to_delete = temp->next;
            temp->next = temp->next->next;
            delete to_delete;
        }
    }

    void display_list() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int count_occurrences(int value) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == value) {
                count++;
            }
            temp = temp->next;
        }
        return count;
    }

    // Bonus: Intersection of two sorted linked lists
    SinglyLinkedList* get_intersection(SinglyLinkedList* list1, SinglyLinkedList* list2) {
        SinglyLinkedList* intersection_list = new SinglyLinkedList();
        Node* temp1 = list1->head;
        Node* temp2 = list2->head;

        while (temp1 && temp2) {
            if (temp1->data == temp2->data) {
                intersection_list->insert_at_tail(temp1->data);
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp1->data < temp2->data) {
                temp1 = temp1->next;
            } else {
                temp2 = temp2->next;
            }
        }
        return intersection_list;
    }
};

int main() {
    // Create two linked lists
    SinglyLinkedList list1;
    SinglyLinkedList list2;

    // Insert elements into list1
    list1.insert_at_head(5);
    list1.insert_at_tail(10);
    list1.insert_at_tail(15);
    list1.insert_at_tail(20);
    list1.insert_at_tail(25);

    // Insert elements into list2
    list2.insert_at_head(10);
    list2.insert_at_tail(15);
    list2.insert_at_tail(30);

    // Display both lists
    cout << "List 1: ";
    list1.display_list();

    cout << "List 2: ";
    list2.display_list();

    // Count occurrences of an element in list1
    int value_to_count = 10;
    cout << "Occurrences of " << value_to_count << " in list 1: " << list1.count_occurrences(value_to_count) << endl;

    // Delete a node from list1
    int value_to_delete = 20;
    list1.delete_node(value_to_delete);
    cout << "List 1 after deleting " << value_to_delete << ": ";
    list1.display_list();

    // Get the intersection of list1 and list2
    SinglyLinkedList* intersection_list = list1.get_intersection(&list1, &list2);
    cout << "Intersection of List 1 and List 2: ";
    intersection_list->display_list();

    // Clean up dynamically allocated intersection list
    delete intersection_list;

    return 0;
}
