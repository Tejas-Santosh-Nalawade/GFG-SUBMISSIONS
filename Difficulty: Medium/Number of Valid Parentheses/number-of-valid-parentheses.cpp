class Solution {
  public:
  
     int f(int i,int ctr,int n,vector<vector<int>>&dp){
         if(i==n){
             if(ctr==0) return 1;
             return 0;
         }
         if(ctr>n/2) return 0;
         
         if(dp[i][ctr]!=-1) return dp[i][ctr];
         
         int way1=f(i+1,ctr+1,n,dp);
         int way2=0;
         if(ctr>0) way2=f(i+1,ctr-1,n,dp);
         
         return dp[i][ctr]=way1+way2;
     }
     
     
     
    int findWays(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n/2+1,-1));
        int x= f(0,0,n,dp);
        return dp[0][0];
        
    }
};