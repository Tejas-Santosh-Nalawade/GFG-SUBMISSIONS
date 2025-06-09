/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
    bool dfs(Node* root, int mini, int maxi) {
    if (root == nullptr) return false;
    if (root->left == nullptr && root->right == nullptr &&
    mini == maxi) {
        return true;
    }
    
    return dfs(root->left, mini, root->data-1) || 
    dfs(root->right, root->data+1, maxi);
}

bool isDeadEnd(Node *root) {
    
    return dfs(root, 1, INT_MAX);
}
};