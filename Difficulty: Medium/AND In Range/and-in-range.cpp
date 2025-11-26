class Solution {
  public:
int andInRange(int l, int r) {
        // code here
        int xl = log2(l), xr = log2(r);
        int ans = 0;
        while(xl>0 && xl==xr) {
            ans+= (1<<(xr));
            l-=(1<<xr);
            r-=(1<<xr);
            xl = log2(l);
            xr = log2(r);
        }
        if(xl==0 && xl==xr) ans++;
        return ans;
    }
};
