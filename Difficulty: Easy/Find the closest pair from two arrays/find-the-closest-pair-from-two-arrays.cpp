class Solution {
  public:
vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x)
{
    int n = arr1.size();
    int m = arr2.size();

    int l = 0, r = m - 1;
    int diff = INT_MAX;
    vector<int> result(2);

    while (l < n && r >= 0)
    {
        int sum = arr1[l] + arr2[r];
        int currDiff = abs(sum - x);

        if (currDiff < diff)
        {
            diff = currDiff;
            result[0] = arr1[l];
            result[1] = arr2[r];
        }

        if (sum > x)
            r--;
        else
            l++;
    }

    return result;
}
};