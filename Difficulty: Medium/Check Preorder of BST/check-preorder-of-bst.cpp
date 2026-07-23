class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        stack<int>st;
        int l = INT_MIN;
        for(int val: arr){
            if(val < l){
                return false;
            }
            while(!st.empty() && val > st.top()){
                l = st.top();
                st.pop();
            }
            st.push(val);
        }
        return true;
    }
};