//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size(); 
        vector<int> res;
        stack<int> stk;
        vector<bool> visited(V, false);
        if (V == 0) return res; 
        stk.push(0);

        while (!stk.empty()) {
            int s = stk.top();
            stk.pop();
            if (visited[s]) continue;
            visited[s] = true;
            res.push_back(s);
            for (int i = adj[s].size() - 1; i >= 0; i--) {
                if (!visited[adj[s][i]]) {
                    stk.push(adj[s][i]);
                }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.dfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends