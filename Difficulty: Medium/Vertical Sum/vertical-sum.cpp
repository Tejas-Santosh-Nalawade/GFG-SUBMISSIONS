/* Structure of binary tree node
class Node{
public:
    int data;
    Node* left, right;
    Node(int item)
    {
        data = item;
        left = nullptr;
        right = nullptr;
    }
}
*/
class DLL{
  public:
  int data;
  DLL *prev, *next;
  DLL(int data){
      this->data = data;
      prev = next = nullptr;
  }
};
class Solution {
  public:
    void solve(Node* root, DLL* head){
        head->data += root->data;
        if(root->left){
            if(!head->prev){
                head->prev = new DLL(0);
                head->prev->next = head;
            }            
            solve(root->left, head->prev);
        }
        if(root->right){
            if(!head->next){
                head->next = new DLL(0);
                head->next->prev = head;
            }
            solve(root->right, head->next);
        }
    }
    vector<int> verticalSum(Node* root) {
       DLL* head = new DLL(0);
       solve(root, head);
       while(head->prev)head = head->prev;
       vector<int> res;
       while(head){
           res.push_back(head->data);
           head = head->next;
       }
       return res;
    }
};