/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
int countNodes(Node* node) {
    int res = 1;
    Node* curr = node;
    while (curr->next != node) {
        res++;
        curr = curr->next;
    }
    return res;
}

// Detects and Counts nodes in loop
int lengthOfLoop(Node* head) {
    Node *slow = head, *fast = head;

    while (slow != nullptr && fast != nullptr 
           && fast->next != nullptr) {
               
        slow = slow->next;
        fast = fast->next->next;

        // If slow and fast meet at
        // some point then there is a loop
        if (slow == fast)
            return countNodes(slow);
    }

    return 0;
}
};