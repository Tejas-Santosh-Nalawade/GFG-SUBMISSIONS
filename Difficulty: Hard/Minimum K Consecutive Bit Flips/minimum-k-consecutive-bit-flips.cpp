class Solution {
  public:
    int kBitFlips(vector<int>& arr, int k) {
        int n = arr.size(), ans = 0;
        vector<int> auxi(n + 1, 0);
        for(int i = 0, s = 0; i < n; i++) {
            s += auxi[i];
            if((arr[i] + s) % 2 == 0) {
                ans++;
                if(i + k > n) return -1;
                s++;
                auxi[i + k]--;
            }
        }
        return ans;
    }
};