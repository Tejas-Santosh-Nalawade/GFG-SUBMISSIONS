class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
      int N = arr.size();
    int totalSum = 0;
    for(int i = 0; i < N; i++){
        totalSum += arr[i];
    }
    
    vector<int> prev(2*totalSum + 1 , 0);
    vector<int> curr;
    prev[totalSum] = 1;
    for(int i = 1 ; i <= N ; i++){
        curr.assign(2*totalSum + 1 , 0);
        for(int sum = 0; sum <= 2*totalSum; sum++){
            
            if(sum + arr[i - 1] <= 2*totalSum)
            curr[sum + arr[i - 1]] += prev[sum];
            
            if(sum - arr[i - 1] >= 0)
            curr[sum - arr[i - 1]] += prev[sum];
            
        }
        prev = curr;
        
    }
    return prev[target + totalSum];
}
};