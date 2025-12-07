class Solution {
  public:
    int distinctSubseq(string &str) {
    int n = str.size();
    int mod = 1000000007;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    vector<int> last(26, -1);

    for(int i = 1; i <= n; i++) {
        dp[i] = (2 * dp[i - 1]) % mod;
        if(last[str[i - 1] - 'a'] != -1) {
            dp[i] = (dp[i] - dp[last[str[i - 1] - 'a']] + mod) % mod;
        }
        last[str[i - 1] - 'a'] = i - 1;
    }
    return dp[n];
    }
};