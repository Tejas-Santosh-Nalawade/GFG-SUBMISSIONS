//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isPossible(int i, int j,int k,vector<vector<char>>& mat, string& word, int n, int m){
        if(!(i >= 0 && i < n) || !(j >= 0 && j < m) || mat[i][j] != word[k]) return false;
        if(k == word.size()-1) return true;
        
        char ch = mat[i][j];
        mat[i][j] = '0';
        bool solveUp = isPossible(i-1, j, k+1, mat, word, n, m);
        bool solveDown = isPossible(i+1, j, k+1, mat, word, n, m);
        bool solveRight = isPossible(i, j+1,k+1, mat, word, n, m);
        bool solveLeft = isPossible(i, j-1, k+1, mat, word, n, m);
        
        mat[i][j] = ch;
        
        return (solveUp || solveDown || solveRight || solveLeft);
    }
  
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size();
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(word[0] == mat[i][j]){
                    if(isPossible(i, j, 0, mat, word, n, m)) return true;
                }
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends