class Solution {
  public:
    int minSubsets(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 1;
        for(int i=0; i<arr.size()-1;i++){
            if(arr[i+1] != arr[i] + 1){
                ans++;
            }
        }
        return ans;
        
    }
};
