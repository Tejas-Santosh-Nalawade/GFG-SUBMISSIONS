class Solution {
  public:
int maxAmount(vector<int> &arr, int k)
{
    const long long MOD = 1000000007;
    int mx = *max_element(arr.begin(), arr.end());
    int lo = 0, hi = mx;

    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        long long cnt = 0;
        for (int x : arr)
        {
            if (x > mid)
                cnt += (x - mid);
        }
        if (cnt > k)
            lo = mid + 1;
        else
            hi = mid;
    }

    int level = lo;

    long long sold = 0;
    long long res = 0;
    for (int x : arr)
    {
        if (x > level)
        {
            long long tickets = x - level;
            sold += tickets;
            res += (1LL * (x + level + 1) * tickets) / 2;
            res %= MOD;
        }
    }
    res = (res + 1LL * (k - sold) * level) % MOD;

    return (int)res;
}

};