class Solution {
  public:
 bool kSubstr(string &s, int k) {
        // code here
        int n=s.length();
        unordered_map<string, int>mpp;
        for(int i=0; i<n; i+=k){
            mpp[s.substr(i, k)]++;
        }
        if(mpp.size()==1) return true;
        if(mpp.size()==2){
            bool freq1=0;
            for(auto &it:mpp){
                if(it.second==1){
                    freq1=1;
                    break;
                }
            }
            return freq1;
        }
        return false;        
    }
};