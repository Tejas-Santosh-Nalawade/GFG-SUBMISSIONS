/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
void sumOfRootToLeaf(Node* root, int sum, int len,int& maxLen, int& maxSum) {
    if (!root) {
        if (len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }
        else if (len == maxLen && sum > maxSum) {
            maxSum = sum;
        }
        return;
    }
    sumOfRootToLeaf(root->left, sum + root->data, len + 1, maxLen, maxSum);
    sumOfRootToLeaf(root->right, sum + root->data, len + 1, maxLen, maxSum);
}
int sumOfLongRootToLeafPath(Node* root) {
    if (!root) return 0;
    int maxSum = INT_MIN, maxLen = 0;
    sumOfRootToLeaf(root, 0, 0, maxLen, maxSum);
    return maxSum;
}
};