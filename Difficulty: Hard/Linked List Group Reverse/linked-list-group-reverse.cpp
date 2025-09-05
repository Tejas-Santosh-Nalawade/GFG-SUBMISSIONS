/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/
struct node {
    int data;
    node* next;
};
class Solution {
 public:
    struct Node *reverseKGroup(Node *head, int k)
    { 
         Node *curr=head;
         Node *prev_first=NULL;
         bool isfirst_pass=true;
         while(curr!=NULL)
         {
             Node *first=curr;
             Node *prev=NULL;
             int count=0;
             while(curr!=NULL && count<k)
             {
                 Node *next=curr->next;
                 curr->next=prev;
                 prev=curr;
                 curr=next;
                 count++;
             }
             if(isfirst_pass)
             {
                 head=prev;
                 isfirst_pass=false;
             }
             
             else
             {
                 prev_first->next=prev;
             }
             prev_first=first;
         }
         return head;
    }
};

