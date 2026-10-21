class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
int n = arr.size();
       int sum =0;
       int minsum = arr[0];
       for(int i =0;i<n;i++){
           sum = sum +arr[i];
           minsum = min(minsum,sum);
           if(sum>0){
               sum =0;
           }
       }
       return minsum;

   }
};