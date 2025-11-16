class Solution {
  public:
int LCIS(vector<int> &a, vector<int> &b) {
    int m = a.size();
    int n = b.size();
    vector<int> dp(n, 0);


    for (int i = 0; i < m; i++) {
        int currentLength = 0;
        for (int j = 0; j < n; j++) {

            if (a[i] == b[j]) {
                dp[j] = max(dp[j], currentLength + 1);
            }
            else if (a[i] > b[j]) {
                currentLength = max(currentLength, dp[j]);
            }

        }
    }
    return *max_element(dp.begin(), dp.end());
}
};