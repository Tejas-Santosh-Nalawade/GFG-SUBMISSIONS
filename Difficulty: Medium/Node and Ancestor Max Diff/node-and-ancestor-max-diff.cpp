/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
      int solve(Node* root,int &maxi){
          if(root == NULL){
              return INT_MAX;
          }
          if(!root->left && !root->right){
              return root->data;
          }
          int left = solve(root->left,maxi);
          int right = solve(root->right,maxi);
          int b = min(left,right);
          maxi = max(maxi,root->data-b);
          int mini = min(root->data,b);
          return mini;
      } 
      int maxDiff(Node* root) {
          int maxi = INT_MIN;
          solve(root,maxi);
          return maxi;
      }
  };

