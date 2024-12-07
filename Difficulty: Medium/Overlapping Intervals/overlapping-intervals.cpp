//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& inter) {
        vector<vector<int>> ans;
         sort(inter.begin(),inter.end());
         ans.push_back(inter[0]);
         int j=0;
         
         int n = inter.size();
         for(int i=1;i<n;i++)
         {
             if(ans[j][1]>=inter[i][0])
             {
                 ans[j][1] = max(inter[i][1],ans[j][1]);
             }
             else if(ans[j][1]<inter[i][0])
             {
                 ans.push_back(inter[i]);
                 j++;
             }
         }
         return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends