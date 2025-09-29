class Solution {
  public:
    int maxSubarrSum(vector<int>& arr, int a, int b) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }

    int maxi = arr[a - 1];

    deque<int> dq;

    dq.push_back(0);

    for (int i = a; i < n; i++) {

        if (i - b - 1 >= 0) {
            if (dq.front() == arr[i - b - 1]) {
                dq.pop_front();
            }
        }
        
        else if (i - b == 0) {
            if (dq.front() == 0) {
                dq.pop_front();
            }
        }

        while (!dq.empty() && dq.back() > arr[i - a]) {
            dq.pop_back();
        }

        dq.push_back(arr[i - a]);

        maxi = max(maxi, arr[i] - dq.front());
    }

    return maxi;
}
};