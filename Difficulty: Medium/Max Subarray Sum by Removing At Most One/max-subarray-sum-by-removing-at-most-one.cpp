class Solution {
  public:
    int maxSumSubarray(vector<int>& arr) {
       int n = arr.size();
       
       int del = arr[0];
       int nextdel = 0;
       
       int ans = arr[0];
       
       for(int i=1; i<n; i++){
           nextdel = max(del, arr[i] + nextdel);
           
           del = max(arr[i], arr[i]+ del);
           
           ans = max(ans , max(del, nextdel));
           
       }
       return ans;
    }
};