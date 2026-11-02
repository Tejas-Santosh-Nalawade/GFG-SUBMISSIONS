class Solution {
  public:
    int maximumSubarray(vector<int>& arr) {
    int withSquare = 0, withoutSquare = 0, ans = INT_MIN;

    for (auto i : arr) {
        withSquare = max(withSquare + i, withoutSquare + (i*i));
        withoutSquare = max(withoutSquare+i, 0);

        ans = max(ans, max(withSquare, withoutSquare));
    }

    return ans;
}
};