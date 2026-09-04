class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size(), ans = 0, temp =0, start =0, end = m-1;
        for(int i=0; i<m; i++){
            temp += arr[i];
        }
        while(start < n){
            ans = max(ans, temp);
            end++;
            end %= n;
            temp+=arr[end];
            temp-=arr[start];
            start++;
        }
        return ans;
    }
};