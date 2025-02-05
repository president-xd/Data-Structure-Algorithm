#include <iostream>
using namespace std;

// Node Structure of Doubly Linked List
struct Node {
    int data;
    Node* next;
    Node* prev;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											General Functions for List											  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to Reverse the List
void reverseList(Node* &List){
	Node* current = List;
	Node* prev = NULL;
	Node* next = NULL;
	
	while (current != NULL){
        next = current->next;  // Save the next node
        current->next = prev;  // Reverse the link

        prev = current;        // Move prev to current
        current = next; 	   // Move current to next
	}
	
	List = prev;	
}

// Template function to print the node data and the additional value of any type
template <typename J>

// Count the occurences in List
void count_occurences(Node* LIST, J value, bool print = false){
	
	// Time complexity O(n);
	
	int counter = 0;
	
	if (LIST == NULL){
		cout << "Sorry, the list is empty.." << endl;
	} else if (LIST->next == NULL && (LIST->data == value)){
		cout << "The number of occurences of " << value << " are : " << counter << endl;
		return;
	}
	
	while (LIST != NULL){
		if (LIST->data == value){
			counter++;
		}
		LIST = LIST->next;
	}
	
	cout << "The number of occurences of " << value << " are : " << counter << endl;
}

// Template function to print the node data and the additional value of any type
template <typename T>

// Finding data in list
bool find_number(Node* List, T value){
	while (List != NULL){
		if (List->data == value){
			return true;
		} else {
			List = List->next;
		}
	}
	return false;
}
// Template function to print the node data and the additional value of any type
template <typename M>

// Supporting function for number_finder function for printing
void number_finder(Node* List, M value){
	if (find_number(List, value)){
		cout << "Number " << value << " was found in the given list." << endl;
	} else{
		cout << "Number " << value << " was not found in the given list." << endl;
	}
}

// Count the occurences in List
int count_occurences(Node* LIST, int number){
	int counter = 0;
	while (LIST != NULL){
		if (LIST->data == number){
			counter++;
		}
		LIST = LIST->next;
	}
	
	return counter;
}

// Nodes Counter with return type int
int nodes_counter(Node* List1){
	int count_nodes = 0;
	
	if (List1 == NULL){
		return 0;
	}
	
	if (List1->next == NULL){
		return 1;
	}
	
	while (List1 != NULL){
		count_nodes++;
		
		List1 = List1->next;
	}
	
	return count_nodes;
}

// Intersection of two lists
void nodes_intersection(Node* List1, Node* List2) {
    if (List1 == NULL || List2 == NULL) {
        if (List1 == NULL) {
            cout << "The List1 is empty.." << endl;
        }
        if (List2 == NULL) {
            cout << "The List2 is empty.." << endl;
        }
        return;
    }

    cout << "The same values between both Lists are : ";

    bool found = false;  // To check if any intersections were found

    // Traverse List1 and check each node's data in List2
    while (List1 != NULL) {
        if (find_number(List2, List1->data)) {
            cout << List1->data << " ";
            found = true;
        }
        List1 = List1->next;
    }

    if (!found) {
        cout << "No common elements found." << endl;
    }
    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											Insertion Functions for List											  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Insert At Beginning
void insertAtBeginning(Node*& List, int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->prev = NULL;
    temp->next = List;  // Set the next pointer to the current List

    if (List != NULL) {
        List->prev = temp;  // Update the previous of the old head
    } else {
    	temp->prev = NULL;  // First node will have prev as NULL
        List = temp;  // Assign temp to List
        return;
	}

    List = temp;  // Update the head to the new node
}

// Insert At Last
void insertAtLast(Node*& List, int data) {
    Node* temp = new Node;
    temp->data = data;
    temp->next = NULL;

    if (List == NULL) {
        temp->prev = NULL;  // First node will have prev as NULL
        List = temp;  // Assign temp to List
        return;
    }

    Node* current = List;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = temp;  // Link the last node to the new node
    temp->prev = current;  // Set the new node's previous to the last node
}

// Insert At Specific Position
void insertAtMiddle(Node* &List, int data, int position) {
    if (position < 0 || position > countNodes(List)) {
        cout << "Position out of range.." << endl;
        return;
    }

    Node* temp = new Node;
    temp->data = data;

    if (position == 0) {
        insertAtBeginning(List, data);
        return;
    }

    Node* current = List;
    int current_position = 0;

    // Traverse to the position where we want to insert
    while (current != NULL && current_position < position - 1) {
        current = current->next;
        current_position++;
    }

    // Inserting in the middle or at the end
    if (current != NULL) {
        temp->next = current->next;  // Set temp's next to current's next
        temp->prev = current;         // Set temp's prev to current

        if (current->next != NULL) {
            current->next->prev = temp; // Set the next node's prev to temp
        }
        
        current->next = temp; // Link current's next to temp
    } else {
        // If we reached this point, we are trying to insert at the end
        temp->next = NULL;
        temp->prev = current; // current should be the last node at this point
        current->next = temp; // Link last node to temp
    }
}

// Printing of Nodes
void getPrinted(Node* List) {
    Node* temp = List;

    while (temp != NULL) {
        cout << "Current Node Address: " << temp << endl;
        cout << "Previous Address : " << temp->prev << endl;
        cout << "Data : " << temp->data << endl;
        cout << "Next Address : " << temp->next << endl;
        cout << "-------------------" << endl;
        temp = temp->next;
    }

    cout << endl;
}

// Main Function
int main() {
    Node* List = NULL;  // Initialize List as NULL

    insertAtBeginning(List, 33);
    insertAtBeginning(List, 90);  // Changing the order for better demonstration
    insertAtLast(List, 66);
	insertAtMiddle(List, 8, 2);
    getPrinted(List);

    // Cleanup memory (not included in the original, but it's good practice)
    while (List != NULL) {
        Node* temp = List;
        List = List->next;
        delete temp;  // Free allocated memory
    }

    return 0;
}
