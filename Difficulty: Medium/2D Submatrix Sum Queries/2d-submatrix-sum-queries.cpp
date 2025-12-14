class Solution {
  public:
    vector<int> prefixSum2D(vector<vector<int>> &arr, vector<vector<int>> &queries) {
    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> prefix(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

       
            prefix[i][j] = arr[i][j];
            if (i > 0)
                prefix[i][j] += prefix[i - 1][j];
            if (j > 0)
                prefix[i][j] += prefix[i][j - 1];
            if (i > 0 && j > 0)
                prefix[i][j] -= prefix[i - 1][j - 1];
        }
    }

    vector<int> result;
    for (auto &q : queries) {
        int r1 = q[0], c1 = q[1];
        int r2 = q[2], c2 = q[3];

        int total = prefix[r2][c2];
        int top = (r1 > 0) ? prefix[r1 - 1][c2] : 0;
        int left = (c1 > 0) ? prefix[r2][c1 - 1] : 0;
        int overlap = (r1 > 0 && c1 > 0) ? prefix[r1 - 1][c1 - 1] : 0;

        int sum = total - top - left + overlap;
        result.push_back(sum);
    }

    return result;
}
};
