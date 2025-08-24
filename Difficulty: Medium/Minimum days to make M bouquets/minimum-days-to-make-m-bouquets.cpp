class Solution {
  public:
bool check(vector<int>& arr, int k, int m, 
           						int days) {
    int bouquets = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= days) {
            cnt += 1;
        }
        else {
            bouquets += cnt / k;
            cnt = 0;
        }
    }

    bouquets += cnt / k;
    return bouquets >= m;
}
int minDaysBloom(vector<int>& arr, int k, int m) {
    int lo = 0;
  	int hi = *max_element(arr.begin(), arr.end());
    int res = -1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;

        if (check(arr, k, m, mid)) {
            res = mid;
            hi = mid - 1;
        }
        else {
            lo = mid + 1;
        }
    }
    return res;
}
};