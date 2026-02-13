
class Solution {
  public:
    int DigitSum(int num){
        int S = 0;
        while(num){
            S += (num % 10);
            num /= 10;
        }
        return S;
    }
    int getCount(int n, int d) {
        int cnt = 0;
        for(int i = d + 1; i <= min(d + 100 , n); i++){
            int S = DigitSum(i);
            if(i - d >= S)
                cnt++;
        }
        int rem = max(0 , n - d - 100);
        cnt += rem;
        return cnt;
    }
};

