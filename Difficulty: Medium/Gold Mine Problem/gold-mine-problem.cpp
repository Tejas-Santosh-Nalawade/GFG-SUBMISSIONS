class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size(),ans=0;
        for(int j=n-2;j>=0;j--){
            for(int i=0;i<n;i++){
                int curr=0;
                curr=max(curr,mat[i][j]+mat[i][j+1]);
                if(i<n-1){
                    curr=max(mat[i][j]+mat[i+1][j+1],curr);
                }
                if(i>0){
                    curr=max(mat[i][j]+mat[i-1][j+1],curr);
                }
                mat[i][j]=curr;
                if(j==0){
                    ans=max(ans,curr);
                }
            }
        }
    return ans;
    }
};