class Solution {
  public:
int tsp(vector<vector<int>>& cost) {
    int n = cost.size();
    if (n <= 1) return n == 1 ? cost[0][0] : 0;
    
    // maximum cost to visit all cities
    const int INF = INT_MAX;
    int FULL = 1 << n, fullMask = FULL - 1;
    
    // dp[mask][i] represents the minimum cost to visit all cities
    // corresponding to the set bits in 'mask', ending at city 'i'
    vector<vector<int>> dp(FULL, vector<int>(n, INF));
    dp[1][0] = 0; 
    
    // iterate over all subsets of cities
    for (int mask = 1; mask < FULL; mask++) {
        for (int i = 0; i < n; i++) {
            
            // skip if city i is not included in mask
            if (!(mask & (1 << i))) continue;
            if (dp[mask][i] == INF) continue;
            
            // try to go to every unvisited city j
            for (int j = 0; j < n; j++) {
                
                // skip if city j is already visited
                if (mask & (1 << j)) continue;
                
                // cost to visit new city j from city i
                // such that previously visited cities
                // remain visited
                int nxt = mask | (1 << j);
                dp[nxt][j] = min(dp[nxt][j],  dp[mask][i] + cost[i][j]);
            }
        }
    }
    
    int ans = INF;
    for (int i = 0; i < n; i++) {
        
        // if last city on path is i and 
        // cost of path is not infinity
        if (dp[fullMask][i] != INF) 
            
            // update net cost such that city 0 is visited in last
            ans = min(ans, dp[fullMask][i] + cost[i][0]);
    }

    return ans;
}

int main() {
    vector<vector<int>> cost = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int res = tsp(cost);
    cout << res;
}

};