class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
    int n = arr.size();
    if (n < 3)
        return {};

    int first = INT_MAX;
    int second = INT_MAX;
    int prevFirst = INT_MAX;

    for (int i = 0; i < n; i++) {
        int x = arr[i];

        if (x <= first) {
            first = x;
        } else if (x <= second) {
            second = x;
            prevFirst = first;
        }
        else {
            return {prevFirst, second, x};
        }
    }
    return {};
        
    }
};