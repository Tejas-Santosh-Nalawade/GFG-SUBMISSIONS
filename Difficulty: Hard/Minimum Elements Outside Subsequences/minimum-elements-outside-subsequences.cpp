class Solution {
public:
    int minCount(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        dp[n][n] = 0;

        for (int k = 0; k < n; k++) {
            vector<vector<int>> ndp = dp;

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    if (dp[i][j] == -1)
                        continue;

                    int cur = dp[i][j];

                    ndp[i][j] = max(ndp[i][j], cur);

                    if (i == n || arr[k] > arr[i]) {
                        ndp[k][j] = max(ndp[k][j], cur + 1);
                    }

                    if (j == n || arr[k] < arr[j]) {
                        ndp[i][k] = max(ndp[i][k], cur + 1);
                    }
                }
            }

            dp = move(ndp);
        }

        int maximumSelected = 0;

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                maximumSelected = max(maximumSelected, dp[i][j]);
            }
        }

        return n - maximumSelected;
    }
};