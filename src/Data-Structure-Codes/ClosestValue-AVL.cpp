#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

// Get height of the node
int height(Node* node) {
    return node ? node->height : 0;
}

// Balance factor
int getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

// Rotate right
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

// Rotate left
Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

// Insert into AVL tree
Node* insert(Node* node, int key) {
    if (!node) return new Node(key);
    if (key < node->data) node->left = insert(node->left, key);
    else if (key > node->data) node->right = insert(node->right, key);
    else return node;

    node->height = max(height(node->left), height(node->right)) + 1;

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

// Find closest value
int findClosest(Node* root, int target) {
    int closest = root->data;
    while (root) {
        if (abs(target - root->data) < abs(target - closest)) {
            closest = root->data;
        }
        if (target < root->data) root = root->left;
        else if (target > root->data) root = root->right;
        else break;
    }
    return closest;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    int target = 28;
    cout << "Closest value to " << target << " is " << findClosest(root, target) << endl;

    return 0;
}
