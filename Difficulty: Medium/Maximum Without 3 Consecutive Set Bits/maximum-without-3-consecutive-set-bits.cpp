class Solution {
  public:
    int maxValue(int n) {
        int i=31;
                int c = 0;
                while(i >= 0){
                    if(n&(1<<i))
                        c++; 
                    else
                        c = 0;
                    if(c == 3){
                        n = (n&(~(1<<i)));
                        c = 0;
                    }
                    i--;
                }
                return n;
        
    }
};