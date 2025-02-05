#include <iostream>

using namespace std;

// Node structure for BST and AVL Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

// Get the height of the node
int height(Node* node) {
    return node ? node->height : 0;
}

// Balance factor for AVL Tree
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Right rotate for AVL Tree
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Left rotate for AVL Tree
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Insert into AVL Tree
Node* insertAVL(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->data) node->left = insertAVL(node->left, key);
    else if (key > node->data) node->right = insertAVL(node->right, key);
    else return node;

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->data) return rotateRight(node);
    if (balance < -1 && key > node->right->data) return rotateLeft(node);
    if (balance > 1 && key > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// Insert into BST
Node* insertBST(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->data) node->left = insertBST(node->left, key);
    else if (key > node->data) node->right = insertBST(node->right, key);
    return node;
}

// Search in Tree
bool search(Node* root, int key, int& comparisons) {
    comparisons = 0;
    while (root) {
        comparisons++;
        if (key == root->data) return true;
        if (key < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

// Measure performance
void measurePerformance(int values[], int n, int searchValue) {
    Node* avlRoot = nullptr;
    Node* bstRoot = nullptr;

    // Insert values into AVL Tree and BST
    for (int i = 0; i < n; i++) {
        avlRoot = insertAVL(avlRoot, values[i]);
        bstRoot = insertBST(bstRoot, values[i]);
    }

    // Search in AVL Tree
    int avlComparisons = 0;
    search(avlRoot, searchValue, avlComparisons);

    // Search in BST
    int bstComparisons = 0;
    search(bstRoot, searchValue, bstComparisons);

    // Output results
    cout << "Search Value: " << searchValue << endl;
    cout << "Comparisons in AVL Tree: " << avlComparisons << endl;
    cout << "Comparisons in BST (unbalanced): " << bstComparisons << endl;
}

int main() {
    // Sample values and search target
    int values[] = { 10, 20, 30, 40, 50, 25, 35, 45, 5, 15 };
    int n = sizeof(values) / sizeof(values[0]);
    int searchValue = 35;
    measurePerformance(values, n, searchValue);
    return 0;
}
