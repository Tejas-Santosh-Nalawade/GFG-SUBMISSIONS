/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
    protected:
    Node* createNode(Node* root, int val){
        if(!root){
            return new Node(val);
            
        }
        if(root->data<val){
            root->right= createNode(root->right, val);
        }
        else{
            root->left= createNode(root->left, val);
        }
        return root;
    }
    private:
    void inorder(vector<int> &ls, Node* root, int &l, int &r){
        if(!root){
            return;
        }
         if(root->data>=l and root->data<=r)
        ls.push_back(root->data);
        inorder(ls, root->left, l, r);
        inorder(ls, root->right, l, r);
    }
  public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        //take Inorder
         vector<int> ls;
         inorder(ls, root, l, r);
        //  return craeteTree( 0, ls.size()-1, ls);
        root= nullptr;
        for(int i=0; i<ls.size();  i++){
            root= createNode(root, ls[i]);
        }
        return root;
         
         
    }
};

