class Solution {
  public:
int atMostX(vector<int> &arr, int x){
    int n = arr.size();

    int odd = 0;
    int ans = 0;
    int start = 0;

    for(int i = 0; i < n; i++) {
        if (arr[i] % 2)
            odd++;

        while (odd > x) {
            if (arr[start] % 2)
                odd--;
            start++;
        }

        ans += i - start + 1;
    }

    return ans;
}

int countSubarrays(vector<int> &arr, int k) {
    int n = arr.size();

    int x = atMostX(arr, k);
    int y = atMostX(arr, k - 1);

    return x - y;
}
};