
/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr)
 {
        
        Node* head=new Node(-1),*t;
        t=head;
        int i;
        
      priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>>q;
      pair<int,Node*> nd;
      int k=arr.size();
      for(i=0;i<k;i++)
          q.push({arr[i]->data,arr[i]});
      
      
      while(!q.empty())
      {
          nd=q.top();
          q.pop();
          
          t->next=new Node(nd.first);
          t=t->next;
          if(nd.second->next!=0)
          {
              q.push({nd.second->next->data,nd.second->next});
          }
          
      }
         return head->next;
    }
};


