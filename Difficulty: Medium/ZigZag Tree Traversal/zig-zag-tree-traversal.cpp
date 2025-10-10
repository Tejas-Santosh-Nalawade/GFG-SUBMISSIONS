/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {

        vector<int> res;
        
        deque<Node*> q;
        q.push_back(root);
        
        bool rev = false;
        
        while(!q.empty()){
            
            int sz = q.size();
            
            while(sz--){
                
                if(rev){
                    Node *n = q.back();q.pop_back();
                    if(n->right){
                        q.push_front(n->right);
                    }
                    if(n->left){
                        q.push_front(n->left);
                    }
                    res.push_back(n->data);
                }else{
                    Node *n = q.front();q.pop_front();
                    if(n->left){
                        q.push_back(n->left);
                    }
                    if(n->right){
                        q.push_back(n->right);
                    }
                    res.push_back(n->data);
                }
            }
            
            rev ^= 1;
        }
        return res;
    }
};