////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											Singly Linked List											  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;                // To hold the value of the node
    struct Node* next;       // Pointer to the next node in the list
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											General Functions for List											  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to Reverse a List
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

// Nodes Counter
void node_counter(Node* List, bool print = false){
	int count_nodes = 0;
	
	if (List == NULL){
		cout << "No Nodes found in the given List.. " << endl;
		return;
	} else if (List->next == NULL){
		count_nodes += 1;
		cout << "No: of nodes in the list are : " << count_nodes << endl; 
		return;
	}
	
	while (List != NULL){
		count_nodes++;
		
		List = List->next;
	}
	
	cout << "No: of nodes in the list are : " << count_nodes << endl;
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

// Printing of Nodes
void getPrinted(Node* List) {
    Node* temp = List;

    while (temp != NULL) {
        cout << "Current Node Address: " << temp << endl;
        cout << "Data : " << temp->data << endl;
        cout << "Next Address : " << temp->next << endl;
        cout << "-------------------" << endl;
        temp = temp->next;
    }

    cout << endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											Insertion Functions for List											  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to add Node at the Beginning
void insertAtBeginning(Node*& LIST, int value) {
    
    // Time Complexity = O(1); // It takes constant time to insert at the head
    
    Node* temp = new Node;    // Create a new node
    temp->data = value;       // Set the data of the new node
    temp->next = LIST;        // Point new node to the current head
    LIST = temp;              // Update head to the new node
}

// Function to add Node at the End
void insertAtLast(Node* LIST, int value) {
    
    // Time complexity = O(n); // It takes time proportional to the number of nodes
    
    Node* temp = new Node;   // Create a new node
    temp->data = value;      // Set the data of the new node
    temp->next = NULL;       // This will be the last node, so next is NULL
    
    Node* current = LIST;    // Start from the head of the list
    while (current->next != NULL) { // Traverse until the last node
        current = current->next; // Move to the next node
    }
    
    current->next = temp;     // Link the new node at the end of the list
}

// Function to add Node at Middle
void insertAtMiddle (Node*& LIST, int value, int position) {  // Pass LIST by reference (&)
    
    // Time Complexity = O(n); // It takes time proportional to the number of nodes
    
    Node* temp = new Node;  // Create a new node
    temp->data = value;     // Set the data of the new node
    temp->next = NULL;

    // If inserting at head (position 0)
    if (position == 0) { 
        temp->next = LIST; // Point new node to the current head
        LIST = temp;       // Update head to the new node
        return;
    }

    // Traverse the list to find the insertion point
    Node* current = LIST;
    int current_position = 0;
    
    while (current != NULL && current_position < position - 1) {
        current = current->next;
        current_position++;
    }
    
    if (current == NULL) {
        cout << "Position out of range." << endl;
        delete temp;  // Clean up the allocated memory if out of range
        return;
    }
    
    temp->next = current->next;  // Link the new node to the next node
    current->next = temp;        // Link the previous node to the new node
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											Deletion Functions for List											  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to delete HEAD node
void deleteHeadNode(Node* &LIST) { 				// Passed Node with &, because & will be used to make changes in main function list too. 
    
    // Time Complexity = O(1); // It takes constant time to delete the head
    
    if (LIST == NULL) { // Check if the list is empty
        cout << "The List was empty. No node to delete." << endl;
        return; // Exit the function
    }
    
    Node* temp = LIST;     // Store the current head node
    
    LIST = LIST->next;     // Update head to point to the next node
    
    delete temp;           // Delete the old head node
}

// Function to delete Last Node
void deleteLastNode(Node*& LIST) { 				// Passed Node with &, because & will be used to make changes in main function list too. 
    
    // Time Complexity = O(n); // It takes time proportional to the number of nodes
    
    if (LIST == NULL) { // Check if the list is empty
        cout << "The list is already empty. No node to delete." << endl;
        return; // Exit the function
    }
    
    if (LIST->next == NULL) { // Check if there is only one node
        cout << "Node deleted successfully!.." << endl;
        
        delete LIST;          // Delete the only node
        LIST = NULL;         // Update the head to NULL (list is now empty)
        return; // Exit the function
    }
    
    Node* temp = LIST;      // Start from the head of the list
    while (temp->next->next != NULL) { // Traverse to the second-to-last node
        temp = temp->next; // Move to the next node
    }
    
    delete temp->next;      // Delete the last node
    temp->next = NULL;      // Set the second-to-last node's next to NULL
}

// Function to delete Middle Node
void deleteMiddleNode(Node*& LIST, int position) { 				// Passed Node with &, because & will be used to make changes in main function list too.
    
    // Time Complexity = O(n); // It takes time proportional to the number of nodes
    
    // Check if the list is empty and the position is 0 (invalid case)
    if (LIST == NULL && position == 0) {
        cout << "The list is already empty. No node to delete." << endl;
        return; // Exit the function
    }
    
    // Check if there is only one node and trying to delete it (position should be 0)
    if (LIST->next == NULL && position == 0) { 
        cout << "Node deleted successfully!.." << endl; // Inform about successful deletion
        
        delete LIST;          // Delete the only node
        LIST = NULL;         // Update the head to NULL (list is now empty)
        return; // Exit the function
    }
    
    Node* temp = LIST;      // Start from the head of the list
    
    // Traverse to the node just before the desired position
    for (int i = 0; i < position - 1; i++) {
        // Check if the current node is NULL (position out of range)
        if (temp == NULL) {
            cout << "Position out of range.." << endl; // Inform about invalid position
            return; // Exit the function
        }
        temp = temp->next; // Move to the next node
    }
    
    // If position is 0, we want to delete the head node
    if (position == 0) {
        Node* to_delete = LIST; // Store the head node to delete
        LIST = LIST->next;      // Update head to point to the next node
        delete to_delete;       // Delete the old head node
        return; // Exit the function
    }
    
    // Check if we are trying to delete the last node
    if (temp->next == NULL) {
        cout << "Node deleted successfully!.." << endl; // Inform about successful deletion
        
        delete temp; // Delete the last node
        temp = NULL; // Set the last node pointer to NULL
        return; // Exit the function
    }
    
    // Delete the node at the specified position
    Node* to_delete = temp->next; // Store the node to delete
    temp->next = temp->next->next; // Bypass the node to delete
    delete to_delete; // Delete the node
}

/*
// Reverse Linked List
void reverse_linked_list(Node* &LIST){
	
}
*/
int main() {
    // Create the head of the linked list
    Node* List = new Node; // Allocate memory for the head node
    List->data = 90;       // Set the data of the head node
    List->next = NULL;     // This is the only node, so next is NULL
    
    insertAtBeginning(List, 45);
    insertAtLast(List, 66);
    
    reverseList(List);
	getPrinted(List);
    
    return 0; // End of program
}

