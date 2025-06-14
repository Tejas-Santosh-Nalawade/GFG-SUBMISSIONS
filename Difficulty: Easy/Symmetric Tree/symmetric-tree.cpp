/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:

bool isSymmetric(Node* root) {
    if (root == nullptr) {
        return true;
    }
    queue<Node*> q;

    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
        
        Node* node1 = q.front(); 
        q.pop();
        Node* node2 = q.front();
        q.pop();

        if (node1 == nullptr && node2 == nullptr) {
            continue;
        }

        if (node1 == nullptr || node2 == nullptr || 
            node1->data != node2->data) {
            return false;
        }
        q.push(node1->left);
        q.push(node2->right);
        q.push(node1->right);
        q.push(node2->left);
    }

    return true;
}

};