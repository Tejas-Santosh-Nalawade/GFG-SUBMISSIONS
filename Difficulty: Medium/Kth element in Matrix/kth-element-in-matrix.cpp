class Solution {
  public:
int countSmallerEqual(const vector<vector<int>>& matrix, int x) {
    int n = matrix.size();
    int count = 0;
    int row = 0;
    int col = n - 1;

    while (row < n && col >= 0) {
        if (matrix[row][col] <= x) {

            count += (col + 1);
            row++;
        } else {
            
            col--;
        }
    }

    return count;
}
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int low = matrix[0][0];
    int high = matrix[n - 1][n - 1];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int count = countSmallerEqual(matrix, mid);

        if (count < k) {

            low = mid + 1;
        } else {

            ans = mid;
            high = mid - 1;
        }
    }

    return ans;
}
};