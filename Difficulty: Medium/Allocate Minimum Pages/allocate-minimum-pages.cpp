class Solution {
  public:
int findPages(vector<int> &arr, int k) {
    int n = arr.size();
    if (k > n) return -1;
    int low = *max_element(arr.begin(), arr.end()); 
    int high = accumulate(arr.begin(), arr.end(), 0); 
    int result = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int studentsRequired = 1, currSum = 0;
        bool isPossible = true;

        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) { 
                isPossible = false;
                break;
            }
            if (currSum + arr[i] > mid) {
                studentsRequired++;
                currSum = arr[i];
                if (studentsRequired > k) {
                    isPossible = false;
                    break;
                }
            } else {
                currSum += arr[i];
            }
        }
        if (isPossible) {
            result = mid; 
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
    return result;
}
};
