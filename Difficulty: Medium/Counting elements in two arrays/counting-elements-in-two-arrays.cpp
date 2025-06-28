class Solution {
  public:
vector<int> countLessEq(vector<int>& a, vector<int>& b) {
     int n = a.size(), m = b.size();
    vector<int> res(n);
    
    int maxi = *max_element(b.begin(), b.end());
    
    vector<int> cnt(maxi + 1, 0);
    for (int i = 0; i < m; i++) {
        cnt[b[i]]++;
    }

    for (int i = 1; i < maxi+1; i++) {
        cnt[i] += cnt[i - 1];
    }

    for (int i = 0; i < n; i++) {
        res[i] = cnt[min(a[i], maxi)];
    }

    return res;
}
};