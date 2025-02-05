#include <iostream>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// In-order traversal to store nodes in an array
void inOrderTraversal(Node* root, int arr[], int& index) {
    if (!root) return;
    inOrderTraversal(root->left, arr, index);
    arr[index++] = root->data;
    inOrderTraversal(root->right, arr, index);
}

// Build a balanced BST from a sorted array
Node* buildBalancedBST(int arr[], int start, int end) {
    if (start > end) return nullptr;
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root->left = buildBalancedBST(arr, start, mid - 1);
    root->right = buildBalancedBST(arr, mid + 1, end);
    return root;
}

// Convert BST to Balanced BST
Node* convertToBalancedBST(Node* root, int n) {
    int* arr = new int[n];
    int index = 0;
    inOrderTraversal(root, arr, index);
    return buildBalancedBST(arr, 0, n - 1);
}

// Pre-order print
void preOrderPrint(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preOrderPrint(root->left);
    preOrderPrint(root->right);
}

int main() {
    // Original BST
    Node* root = new Node(10);
    root->right = new Node(20);
    root->right->right = new Node(30);
    root->right->right->right = new Node(40);
    
    cout << "Original Tree (Pre-order): ";
    preOrderPrint(root);
    cout << endl;
    
    root = convertToBalancedBST(root, 4);

    cout << "Balanced AVL Tree (Pre-order): ";
    preOrderPrint(root);
    cout << endl;

    return 0;
}
