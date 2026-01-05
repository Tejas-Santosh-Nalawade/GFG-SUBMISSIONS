class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int sum = 0;
        for(int itr = 0;itr<k-1;itr++)sum+=arr[itr];
        int maxi = -1;
        for(int itr = k-1, i = 0;itr<arr.size();itr++,i++){
            sum+=arr[itr];
            maxi = max(maxi, sum);
            sum-=arr[i];
        }
        return maxi;
    } 
};