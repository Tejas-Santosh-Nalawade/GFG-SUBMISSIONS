class Solution {
  public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int curr = mat[i][j];
                bool isPeek = true;
                
                // check top
                if(i > 0 && mat[i-1][j] > curr){
                    isPeek = false;
                }
                // check bottom
                if(i+1 < n && mat[i+1][j] > curr){
                    isPeek = false;
                }
                // check left
                if(j > 0 && mat[i][j-1] > curr){
                    isPeek = false;
                }
                // check right
                if(j + 1 < m && mat[i][j+1] > curr){
                    isPeek = false;
                }
                
                if(isPeek){
                    return {i,j};
                }
            }
             
        }
        return {-1,-1};
       
        
    }
};
