class Solution {
  public:
    string largestSwap(string &s) {
        char maximum = '0';
        int maxIndex = -1;
        int l=-1,r = -1;
        for(int i= s.size()-1; i>=0 ; i-- ){
            if(s[i] > maximum){
                maximum = s[i];
                maxIndex = i; 
            }
            else if (s[i] < maximum){
                l = i;
                r = maxIndex;
            }
        }
        
         if (l == -1) return s;
         swap(s[l], s[r]);
         
         
        return s;
        
    }
};