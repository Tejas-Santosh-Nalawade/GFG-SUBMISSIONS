/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
int countNodes(Node* root) {
    Node* curr = root;
    int nodes = 0;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            nodes++;
            curr = curr->right;
        } else {
            
            // Find the inorder predecessor of curr
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            // Make curr the right child of its inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                
                // Revert the changes made in the tree structure
                prev->right = nullptr;
                curr = curr->right;
                nodes++;
            }
        }
    }
    return nodes;
}

// Function to find median of BST
int findMedian(Node* root) {
    int n = countNodes(root);
    int medianIndex;

    // 1 based index
    if (n % 2 == 0) medianIndex = n / 2;
    else medianIndex = (n + 1) / 2;

    Node* curr = root;
    int nodes = 0;
    while (curr != nullptr) {
        if (curr->left == nullptr) {
            nodes++;
            if (nodes == medianIndex) return curr->data;
            curr = curr->right;
        } else {
            
            // Find the inorder predecessor of curr
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }
            
            // Make curr the right child of its inorder predecessor
            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                nodes++;
                if (nodes == medianIndex) return curr->data;
                
                // Revert the changes made in the tree structure
                prev->right = nullptr;
                curr = curr->right;
            }
        }
    }
    return -1;
}
};