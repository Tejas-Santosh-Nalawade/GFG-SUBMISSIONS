//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

bool isSafe(int row,int col,vector<vector<bool>>&board,int n){
        int x =row;
        int y=col;
      while(y>=0){
          if(board[x][y]==1)
          return false;
           y--;
      }
     x=row;
     y=col;
     while(y>=0 && x>=0){
          if(board[x][y]==1)
          return false;
           y--;
           x--;
      }
     x=row;
     y=col;
     while(y>=0 && x<n){
          if(board[x][y]==1)
          return false;
           y--;
           x++;
      }
      return true;
}
void solve(int col,vector<vector<bool>>&board,vector<vector<int>>&ans,int n){
      if(col==n){
          vector<int>temp;
          for(int col=0;col<n;++col){     
               for(int row=0;row<n;++row){ 
                   if(board[row][col]==1){
                       temp.push_back(row+1);
                   }
               }
          }
          ans.push_back(temp);
           return;
      }
        
        for(int row=0;row<n;++row){
             if(isSafe(row,col,board,n)){
                    board[row][col]=1;
                    solve(col+1,board,ans,n);
                    board[row][col]=0;
             }
        }
}
class Solution{
public:
    vector<vector<int>> nQueen(int n) {
         vector<vector<int>>ans;
         vector<vector<bool>>board(n,vector<bool>(n,0));
          solve(0,board,ans,n);
          return ans;
         
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends