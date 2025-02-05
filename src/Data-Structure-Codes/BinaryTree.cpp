#include <iostream>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

// Node Structure of Binary Tree
struct Node{
	int data;
	Node* left;
	Node* right;
	
	Node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// Insertion Function in Binary Tree
Node* insert(Node* node, int value){
	if (node == NULL) return new Node(value);
	
	if (value < node->data){
		node->left = insert(node->left, value);
	} else {
		node->right = insert(node->right, value);
	}
	
	return node;
}

// Function to print PreOrder of the Binary Tree
void PreOrder(Node* root){
	
	if (root == NULL){
		return;
	}
	
	cout << root->data << " ";
	
	PreOrder(root->left);
	PreOrder(root->right);
} 

// Function to print InOrder of the Binary Tree
void InOrder(Node* root){
	
	if (root == NULL){
		return;
	}
	
	InOrder(root->left);
	cout << root->data << " ";
	InOrder(root->right);
}

// Function to print PostOrder of the Binary Tree
void PostOrder(Node* root){
	
	if (root == NULL){
		return;
	}
	
	PostOrder(root->left);
	PostOrder(root->right);
	cout << root->data << " ";
}

// Function to Insert the Node in Binary Tree
Node* InsertNode(Node* root, int value){
	
	if (root == NULL){
		return root = new Node(value);
	}
	
	if (value < root->data){
		root->left = InsertNode(root->left, value);
	} else {
		root->right = InsertNode(root->right, value);
	}
	
	return root;
}

// Helper Function for BST check Function
bool isBST_helper(Node* root, int min, int max){
	
	if (root == NULL){
		return true;
	}
	
	if (root->data < min || root->data > max){
		return false;
	}
	
	return isBST_helper(root->left, min, root->data - 1) && isBST_helper(root->right, root->data + 1, max);
}


// Function to check whether the Tree is Binary or Not.
bool checkBST(Node* root){
	
	return isBST_helper(root, INT_MIN, INT_MAX);
}

// Main Function
int main(){
	
	Node* root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	//root->right->left = new Node(1020);
	//root->right->right = new Node(1120);
	insert(root, 9);
	
	cout << "PreOrder of the Binary Tree : " << endl;
	PreOrder(root);
	cout << endl;
	
	cout << "InOrder of the Binary Tree : " << endl;
	InOrder(root);
	cout << endl;
	
	cout << "PostOrder of the Binary Tree : " << endl;
	PostOrder(root);
	cout << endl;
	
	if (checkBST(root)){
		cout << "It is a Binary Tree.." << endl;
	} else {
		cout << "It is not a Binary Tree.." << endl;
	}
	
	return 0;
}
