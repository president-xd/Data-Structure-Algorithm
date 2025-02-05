#include <iostream>
#include <string>
using namespace std;

// Structure of Tree (For the LeaderBoard);
struct Node{
    int score;
    string name;
    Node* left;
    Node* right;
    
    Node(string name, int score){
        this->name = name;
        this->score = score;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to input the name of players along with their score;
Node* insert(Node* root, int score){

    if (root == NULL){
        return new Node(score);
    }

    if (score < root->score){
        root->left = insert(root->left, score);
    } else {
        root->right = insert(root->right score);
    }

    return root;
}

// Function to print the Tree in InOrder form;
void inorder(Node* root){
    
    if (root == NULL){
        cout << "Try Again.." << endl;
        return;
    }

    inorder(root->left);
    cout << root->name << " = " << root->score << " ";
    inorder(root->right);
}

// Function to print the Tree in PreOrder form;
void preorder(Node* root){
    
    if (root == NULL){
        cout << "Try Again.." << endl;
        return;
    }

    cout << root->name << " = " << root->score << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to print the Tree in PostOrder form;
void postorder(Node* root){
    
    if (root == NULL){
        cout << "Try Again.." << endl;
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->name << " = " << root->score << " ";
}
/*
// Function for printing the Score;
void print_players(Node* root, string order){

    if (root == NULL){
        cout << "The LeaderBoard is empty.. Try to enter players" << endl;
	return;
    }

    if (order == "InOrder"){
        inorder(root);
    } else if (order == "PreOrder"){
        preorder(root);
    } else if (order == "PostOrder"){
        postorder(root);
    } else {
        cout << "Wrong Order, Brother" << endl;
    }

}

// Function to search Players by their name;
Node* searchByName(Node* root, string name){

    if (root == NULL){
        cout << "The LeaderBoard is Empty.. Try to enter players" << endl;
        return NULL;
    }

    if (root->name == name) return root;
    
    if ( name < root->name){
        return searchByName(root->left, name);
    }

    return searchByName(root->right, name);
}

// Function to find the minimum score from the LeaderBoard;
Node* findMinimum(Node* root){

    if (root == NULL){
        cout << "The LeaderBoard is Empty.. Try to enter players" << endl;
        return root;
    }

    while (root && root->left != NULL){
        root = root->left;
    }

    return root;
}

// Function to find the maximum score from the LeaderBoard;
Node* findMaximum(Node* root){

    if (root == NULL){
        cout << "The LeaderBoard is Empty.. Try to enter players" << endl;
        return root;
    }

    while (root && root->right != NULL){
        root = root->right;
    }

    return root;
}

*/
int main(){
    Node* root = NULL;

    // Insert players into the leaderboard
    root = insert(root, "Alice", 90);
    root = insert(root, "Bob", 75);
    root = insert(root, "Charlie", 85);
    root = insert(root, "Diana", 95);
    root = insert(root, "Eve", 65);

    // Print the leaderboard
    cout << "Leaderboard (InOrder):" << endl;
    print_players(root, "InOrder");

    cout << "Leaderboard (PreOrder):" << endl;
    print_players(root, "PreOrder");

    cout << "Leaderboard (PostOrder):" << endl;
    print_players(root, "PostOrder");

    // Search for a player
    string searchName = "Charlie";
    Node* player = searchByName(root, searchName);
    if (player != NULL) {
        cout << searchName << " found with score: " << player->score << endl;
    } else {
        cout << searchName << " not found in the leaderboard." << endl;
    }

    // Find minimum and maximum scores
    Node* minNode = findMinimum(root);
    if (minNode != NULL) {
        cout << "Lowest score: " << minNode->name << " = " << minNode->score << endl;
    }

    Node* maxNode = findMaximum(root);
    if (maxNode != NULL) {
        cout << "Highest score: " << maxNode->name << " = " << maxNode->score << endl;
    }

    return 0;

}
