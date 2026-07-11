class Solution {
  public:
   int solve(vector<vector<int>>&mat,vector<vector<bool>>&visited,int i,int j,int a,int b){
       if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || visited[i][j] || mat[i][j]==0)
        return 0;
    
        if(i==a and j==b)
            return 1;
        int x=0;
        
        visited[i][j]=true;
        
        x=max(x,solve(mat,visited,i+1,j,a,b));
        x=max(x,solve(mat,visited,i,j-1,a,b));
        x=max(x,solve(mat,visited,i,j+1,a,b));
        x=max(x,solve(mat,visited,i-1,j,a,b));
        
        visited[i][j]=false;
        
        if(x==0)
            return 0;
        return x+1;
        
    }

    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        return solve(matrix,visited,xs,ys,xd,yd)-1;

    }
    
};