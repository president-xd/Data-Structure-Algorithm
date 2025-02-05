// In-order traversal to find the kth smallest element
void inOrder(Node* root, int& count, int k, int& result) {
    if (!root) return;
    inOrder(root->left, count, k, result);
    count++;
    if (count == k) {
        result = root->data;
        return;
    }
    inOrder(root->right, count, k, result);
}

// Find the kth smallest element in the AVL tree
int kthSmallest(Node* root, int k) {
    int count = 0, result = -1;
    inOrder(root, count, k, result);
    return result;
}
