class Solution {
  public:
pair<string, int> matrixChainOrderRec(vector<int> &arr, 
	int i, int j, vector<vector<pair<string, int>>> &memo) {

    if (i == j) {
        string temp = "";
        temp += char('A' + i);
        return {temp, 0};
    }

    if (memo[i][j].second != -1)
        return memo[i][j];

    int res = INT_MAX;
    string str;

    for (int k = i + 1; k <= j; k++) {
        pair<string, int> left = matrixChainOrderRec(arr, i, k - 1, memo);
        pair<string, int> right = matrixChainOrderRec(arr, k, j, memo);

        int curr = left.second + right.second + arr[i] * arr[k] * arr[j + 1];
        if (res > curr)
        {
            res = curr;
            str = "(" + left.first + right.first + ")";
        }
    }

    return memo[i][j] = {str, res};
}

string matrixChainOrder(vector<int> &arr) {
    int n = arr.size();
    vector<vector<pair<string, int>>> memo
      (n, vector<pair<string, int>>(n, {"", -1}));
    return matrixChainOrderRec(arr, 0, n - 2, memo).first;
}
};