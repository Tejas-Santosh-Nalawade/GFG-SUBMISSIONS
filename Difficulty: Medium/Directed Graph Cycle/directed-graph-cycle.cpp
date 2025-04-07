//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(V);
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        // Directed edge from edge[0] to edge[1]
    }
    return adj;
}
bool isCyclic(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adj = constructAdj(V, edges);
    // Build the adjacency list

    vector<int> inDegree(V, 0); // Array to store in-degree of each vertex
    queue<int> q;               // Queue to store nodes with in-degree 0
    int visited = 0;            // Count of visited (processed) nodes

    // Step 1: Compute in-degrees of all vertices
    for (int u = 0; u < V; ++u)
    {
        for (int v : adj[u])
        {
            inDegree[v]++;
        }
    }

    //  Add all vertices with in-degree 0 to the queue
    for (int u = 0; u < V; ++u)
    {
        if (inDegree[u] == 0)
        {
            q.push(u);
        }
    }

    // Perform BFS (Topological Sort)
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        visited++;

        // Reduce in-degree of neighbors
        for (int v : adj[u])
        {
            inDegree[v]--;
            if (inDegree[v] == 0)
            {
                // Add to queue when in-degree becomes 0
                q.push(v);
            }
        }
    }

    //  If visited nodes != total nodes, a cycle exists
    return visited != V;
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends