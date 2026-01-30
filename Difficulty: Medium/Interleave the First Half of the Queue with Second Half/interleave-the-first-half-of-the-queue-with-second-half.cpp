class Solution {
  public:
 void rearrangeQueue(queue<int> &q) {
        vector<int> v;
        
        while(q.size()){
            v.push_back(q.front());
            q.pop();
        }
        
        int sz=v.size()/2,ct=sz,i=0;
        while(ct--){
            cout<<v[i]<<" "<<v[i+sz]<<" ";
            i++;
        }
    }
};