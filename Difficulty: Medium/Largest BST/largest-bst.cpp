/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

struct Info {
    bool isBST;
    int size;
    int minVal, maxVal;
};

class Solution {
    Info solve(Node* node) {
        if (node == NULL)
            return {true, 0, INT_MAX, INT_MIN};

        Info left  = solve(node->left);
        Info right = solve(node->right);

        if (left.isBST && right.isBST
            && node->data > left.maxVal
            && node->data < right.minVal) {
            return {
                true,
                1 + left.size + right.size,
                min(node->data, left.minVal),
                max(node->data, right.maxVal)
            };
        }

        return {false, max(left.size, right.size), 0, 0};
    }

public:
    int largestBst(Node* root) {
        return solve(root).size;
    }
};