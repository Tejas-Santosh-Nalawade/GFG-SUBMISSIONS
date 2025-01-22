//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
 Node* rev(Node* root){
       if(!root) return NULL; 
       Node* curr = root; 
       Node* prev = NULL; 
       Node* next; 
       
       while(curr){
           next = curr->next; 
           curr->next = prev; 
           prev  = curr; 
           curr = next; 
       }
       
       return prev; 
   }
    Node* addTwoLists(Node* num1, Node* num2) {
        int carry = 0; 
        Node* ans = new Node(-1); 
        Node* res = ans; 
        Node* one = rev(num1);
        Node* two = rev(num2); 
        
        while(one&&two){
            int cal = one->data+two->data+carry; 
            carry = cal/10; 
            cal = cal%10; 
            Node* tmp = new Node(cal); 
            ans->next = tmp;
            ans = ans->next; 
            one = one->next;
            two = two->next; 
        }
        
        while(one){
             int cal = one->data+carry; 
            carry = cal/10; 
            cal = cal%10; 
            Node* tmp = new Node(cal); 
            ans->next = tmp;
            ans = ans->next; 
            one = one->next;
        }
        
         while(two){
             int cal = two->data+carry; 
            carry = cal/10; 
            cal = cal%10; 
            Node* tmp = new Node(cal); 
            ans->next = tmp;
            ans = ans->next; 
            two = two->next;
        }
        
        if(carry>0){
             Node* tmp = new Node(carry); 
            ans->next = tmp;
            ans = ans->next; 
        }
        Node* realans = rev(res->next);
         while(realans->data==0){
            realans = realans->next; 
        }
        return realans; 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends