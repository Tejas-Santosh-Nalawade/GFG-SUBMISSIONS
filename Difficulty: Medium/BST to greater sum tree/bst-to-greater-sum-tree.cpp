/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
  public:
void updateTree(Node* root, int& sum) {
    if (root == nullptr) {
        return;
    }

    // Traverse the right subtree first (larger values)
    updateTree(root->right, sum);

    // Update the sum and the current node's value
    sum += root->data;
    root->data = sum - root->data;

    // Traverse the left subtree (smaller values)
    updateTree(root->left, sum);
}

// Return the updated tree
void transformTree(Node* root) {
  
  	// Initialize the cumulative sum
    int sum = 0; 
    updateTree(root, sum);
}
};