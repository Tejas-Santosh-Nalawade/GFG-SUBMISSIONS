// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        int n =arr.size();
        sort(arr.begin(),arr.end());
        int mini =0;
        int maxi =0;
        int min_diff= arr[n - 1] - arr[0];
        for(int i =1;i< n;i++){
            if(arr[i] < k)
                continue;
                
                mini = min(arr[0] + k,arr[i] - k);
                maxi = max(arr[n - 1] - k,arr[i -1] + k);
                
                min_diff = min(min_diff,maxi - mini);
        }
        return min_diff;
    }
};
