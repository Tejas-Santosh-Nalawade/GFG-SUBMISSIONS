//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private:
    bool detectCycles(int src, vector<vector<int>> &adj, vector<int> &vis){
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});  // (node, parent)

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int adjNode : adj[node]) {
                if (!vis[adjNode]) {  
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }  
                // **Fix:** Ensure the detected node is not just the immediate parent in an undirected graph.
                else if (adjNode != parent) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<int> vis(V, 0);  // Visited array

        for(int i = 0; i < V; i++){
            if(!vis[i]) {
                if(detectCycles(i, adj, vis)) {
                    return true;
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
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
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