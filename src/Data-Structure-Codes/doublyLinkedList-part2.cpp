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
int countNodes(Node* List1){
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
//											Insertion Functions for List										  //
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//											Deletion Functions for List										      //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Function to Delete Head Node
void deleteAtBeginning(Node* &List){
	Node* temp = List;
	
	if (List == NULL){
		cout << "Empty List, No Node to delete.." << endl;
		return;
	}
	
	List = List->next;
	List->prev = NULL;
	
	delete temp;
}

// Function to Delete Last Node
void deleteAtLast(Node* &List) {
    if (List == NULL) {
        cout << "Empty List, No Node to delete.." << endl;
        return;
    }

    Node* temp = List;

    // If there is only one node in the list
    if (temp->next == NULL) {
        delete temp;
        List = NULL;  // Update head to NULL, as the list will be empty
        return;
    }

    // Traverse the list to find the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Now temp is pointing to the last node
    temp->prev->next = NULL;  // Update the second-to-last node's next to NULL

    delete temp;  // Delete the last node
}

// Function to Delete Middle Node
void deleteAtMiddle(Node* &List, int position){
	
	if (position <= 0){
		cout << "Invalid Position, Try Again.." << endl;
		return;
	} else if (List == NULL){
		cout << "The node is already empty, ..." << endl;
		return;
	} else if (countNodes(List) < position - 1){
		cout << "Position out of range.." << endl;
		return;
	} else if (List->next == NULL && position == 0) { 
        cout << "Node deleted successfully!.." << endl; // Inform about successful deletion
        
        delete List;          // Delete the only node
        List = NULL;         // Update the head to NULL (list is now empty)
        return; // Exit the function
    }
    
    Node* temp = List;      // Start from the head of the list
    
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
        Node* to_delete = List; // Store the head node to delete
        List = List->next;      // Update head to point to the next node
        List->prev = NULL;
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
    
    temp = temp->next;
    // Delete the node at the specified position
    Node* to_delete = temp;  // Store the node to delete
    temp->prev->next = temp->next;
    temp = temp->next;
    delete to_delete; // Delete the node
}

// Main Function
int main() {
    Node* List = NULL;  // Initialize List as NULL

    insertAtBeginning(List, 33);
    insertAtBeginning(List, 90);  // Changing the order for better demonstration
    insertAtLast(List, 66);
	insertAtMiddle(List, 8, 2);
	
	getPrinted(List);
	cout << endl;
	
	deleteAtMiddle(List, 2);
    getPrinted(List);

    // Cleanup memory (not included in the original, but it's good practice)
    while (List != NULL) {
        Node* temp = List;
        List = List->next;
        delete temp;  // Free allocated memory
    }

    return 0;
}
