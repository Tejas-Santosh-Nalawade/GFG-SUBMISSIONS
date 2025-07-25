class Solution {
  public:
int fastPow(int base, int exp) {
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

int countValid(int n, vector<int> &arr) {

    bool good[10] = {};
    for (int d : arr) good[d] = true;

    int f = 0, f0 = 0;
    for (int d = 0; d < 10; d++) {
        if (!good[d]) {
            f++;
            if (d != 0) f0++;
        }
    }
    int total = 9 * fastPow(10, n - 1);
    
    int noneAllowed = (n == 1 ? f0 : f0 * fastPow(f, n - 1));
    return total - noneAllowed;
}
};
