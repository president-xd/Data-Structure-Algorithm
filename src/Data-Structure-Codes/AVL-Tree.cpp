#include <iostream>
using namespace std;

// Node Structure of Binary Tree
struct Node {
    int data;
    int height;
    Node* right;
    Node* left;

    Node(int data) {
        this->data = data;
        this->height = 1;
        this->left = this->right = NULL;
    }
};

// Function to return the height of the Tree
int getHeight(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

// Function to get Balance of the AVL Tree
int getBalance(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

// Right Rotation Function
void rightRotation(Node* &root) {
    Node* child = root->left;
    Node* childRight = child->right;

    child->right = root;
    root->left = childRight;

    // Update the Height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

    root = child;
}

// Left Rotation Function
void leftRotation(Node* &root) {
    Node* child = root->right;
    Node* childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    // Update the Height
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    child->height = max(getHeight(child->left), getHeight(child->right)) + 1;

    root = child;
}

// Find the minimum value node in a tree
Node* findMinimum(Node* root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

// Function to insert the Node
void insert(Node* &root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return;
    }

    if (data < root->data) {
        insert(root->left, data);
    } else if (data > root->data) {
        insert(root->right, data);
    } else {
        return;
    }

    // Update the height of the tree
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Balancing Check
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && data < root->left->data) {
        rightRotation(root);
    }

    // Right Right Case
    else if (balance < -1 && data > root->right->data) {
        leftRotation(root);
    }

    // Left Right Case
    else if (balance > 1 && data > root->left->data) {
        leftRotation(root->left);
        rightRotation(root);
    }

    // Right Left Case
    else if (balance < -1 && data < root->right->data) {
        rightRotation(root->right);
        leftRotation(root);
    }
}

// Function to delete the Node
Node* deleteNode(Node* root, int data) {
    // Base condition
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node to be deleted found

        // Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {  // No child case
                temp = root;
                root = NULL;
            } else {  // One child case
                *root = *temp;  // Copy the contents of the non-empty child
            }

            delete temp;
        } else {
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMinimum(root->right);

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
    }

    // If the tree had only one node then return
    if (root == NULL) {
        return root;
    }

    // Update the height of the current node
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    // Balance the node
    int balance = getBalance(root);

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0) {
        rightRotation(root);
    }

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        leftRotation(root->left);
        rightRotation(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0) {
        leftRotation(root);
    }

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        rightRotation(root->right);
        leftRotation(root);
    }

    return root;
}

void preOrder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Main Function
int main() {
    Node* root = NULL;

    // Inserting nodes
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 25);

    // PreOrder Traversal
    cout << "PreOrder Traversal of the constructed AVL tree is: ";
    preOrder(root);
    cout << endl;

    // Deleting nodes
    root = deleteNode(root, 10);
    cout << "PreOrder Traversal after deleting 10: ";
    preOrder(root);
    cout << endl;

    root = deleteNode(root, 30);
    cout << "PreOrder Traversal after deleting 30: ";
    preOrder(root);
    cout << endl;

    return 0;
}
