class Solution {
  public:
    bool isPossible(int n, int m, string& s) {
        int l = 0;
        int r = 0;
        int u = 0;
        int d = 0;

        for(auto c : s){

            if(c=='R'){
                r++;
                if(l)l--;
                if(r>=m)return 0;
            }
            else if(c=='L'){
                l++;
                if(r)r--;
                if(l>=m)return 0;
            }
            else if(c=='U'){
                u++;
                if(d)d--;
                if(u>=n)return 0;
            }
            else{
                d++;
                if(u)u--;
                if(d>=n)return 0;
            }

        }

        return 1;
    }
};