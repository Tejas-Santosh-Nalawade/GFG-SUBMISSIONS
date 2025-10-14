/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
if (root == nullptr) return 0;
    if (root->data < l) {
        return nodeSum(root->right, l, r);
    }
    
    else if (root->data > r) {
        return nodeSum(root->left, l, r);
    }
    
    int left = nodeSum(root->left, l, r);
    int right = nodeSum(root->right, l, r);
    
    return left + right + root->data;
}
};
