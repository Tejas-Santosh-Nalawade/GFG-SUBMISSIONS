class Solution {
  public:
bool check(vector<int>& arr, int mid, int k) {
    int hours = 0;
    for (int i = 0; i < arr.size(); i++) {
        hours += arr[i] / mid;
        if (arr[i] % mid != 0) {
            hours++;
        }
    }
    return hours <= k;
}

int kokoEat(vector<int>& arr, int k) {
    int lo = 1;
    int hi = *max_element(arr.begin(), arr.end());
    int res = hi;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (check(arr, mid, k)) {
            res = mid;       
            hi = mid - 1;
        } else {
            lo = mid + 1;    
        }
    }

    return res;
}
};