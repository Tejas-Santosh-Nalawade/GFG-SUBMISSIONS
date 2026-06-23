class Solution {
  public:
    int maxPeopleDefeated(int p) {
    long long s = 1;
        long long e = 1800;
        long long mid = s+(e-s)/2;
        long long temp = -1;
        while(s <= e){
           if((mid*(mid+1)*(2*mid+1))/6 == p){
               return (int)mid;
           }
           else if((mid*(mid+1)*(2*mid+1))/6 < p){
               temp = mid;
               s = mid + 1;
           }
           else{
               e = mid - 1;
           }
           mid = s+(e-s)/2;
        }
        return (int)temp;
    }
};
