class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        int n  = arr.size();
        unordered_map<int,int>mp;
        int maximum = 0, b ,c;
        for(auto i : arr){
            b = i-1, c = i + 1;
            mp[i] = max(mp[b], mp[c]) + 1;
            maximum = max(maximum, mp[i]);
        }
        return maximum;
        
    }
};