class Solution {
  public:
   int minCost(string &s, string &t, vector<vector<char>> &transform,
                vector<int> &cost) {
        int n = s.length();
        vector<pair<int,int>> adj[26];
        for (int i = 0; i < (int)transform.size(); ++i) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            adj[u].push_back({v, cost[i]});
        }

        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));

        // Dijkstra from each node
        //calculating distance from one character to all the other
        //26 character 
        for (int src = 0; src < 26; ++src) {
            dist[src][src] = 0;
            priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
            pq.push({0, src});
            while (!pq.empty()) {
                auto [d, u] = pq.top(); pq.pop();
                if (d > dist[src][u]) continue;
                for (auto &e : adj[u]) {
                    int v = e.first, w = e.second;
                    if (dist[src][v] > d + w) {
                        dist[src][v] = d + w;
                        pq.push({dist[src][v], v});
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            char a = s[i], b = t[i];
            if (a == b) continue;

            int x = a - 'a', y = b - 'a';
            int best = INF;
            // try every possible final character z
            //here in this we can change from a->c or b->c
            // so thats why checking it from all 0-25 characters
            for (int z = 0; z < 26; ++z) {
                if (dist[x][z] < INF && dist[y][z] < INF) {
                    best = min(best, dist[x][z] + dist[y][z]);
                }
            }
            if (best == INF) return -1;
            ans += best;
        }
        return (int)ans;
    }
};