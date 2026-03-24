class Solution {
  public:
bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>> graph(n);
    vector<int> inDegree(n, 0);
   
    for (auto& pre : prerequisites) {
        int dest = pre[0];
        int src = pre[1];
        graph[src].push_back(dest);
        inDegree[dest]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (inDegree[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int child : graph[node]) {
            inDegree[child]--;
            if (inDegree[child] == 0)
                q.push(child);
        }
    }
    
    for (int i = 0; i < n; i++)
        if (inDegree[i] != 0)
            return false;

    return true;
}
};