class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        int n = arr.size();
        stable_sort(arr.begin(), arr.end(), [x](int a, int b) {
        if (abs(a - x) < abs(b - x))
            return true;
        else
            return false;
    });
    }
};