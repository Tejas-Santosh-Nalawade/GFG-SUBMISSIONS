class Solution {
  public:
    int maxProduct(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int i=2;i<=n;i++){
            int t = 0;
            for(int j=1;j<i;j++){
                t = max({t,(i-j)*j,dp[i-j]*j});
            }
             dp[i] = max(dp[i],t);
        }
        return dp[n];
    }
};