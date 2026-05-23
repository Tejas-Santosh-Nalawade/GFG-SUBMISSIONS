/* Structure for Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
    int solve(Node* root){
        if(root == nullptr){
            return 0;
        }
        int left = solve(root->left);
        int right = solve(root->right);
        int original = root->data;
        root->data = left + right;
        
        return original + root->data;
    }
    
    void toSumTree(Node *root) {
        solve(root);
        
    }
};