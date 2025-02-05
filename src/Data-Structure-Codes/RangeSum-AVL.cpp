int rangeSum(Node* root, int low, int high) {
    if (!root) return 0;
    int sum = 0;
    if (root->data >= low && root->data <= high) sum += root->data;
    if (root->data > low) sum += rangeSum(root->left, low, high);
    if (root->data < high) sum += rangeSum(root->right, low, high);
    return sum;
}
