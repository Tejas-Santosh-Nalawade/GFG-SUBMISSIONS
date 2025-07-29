class Solution {
  public:
    vector<int> asciirange(string& s) {
    int n = s.size();
    int curr = 0;
    vector<int> first(26, -1), last(26, -1);
    vector<int> prefix(n, 0);
    vector<int> res;
    
    for (int i =0 ; i < n; i++) {
        int num = s[i] - 'a';
        if (first[num] == -1)  first[num] = i;
        else    last[num] = i;
        
        if (i == 0) prefix[i] = s[i];
        else    prefix[i] = prefix[i - 1] + s[i];
    }
    
    for (int i = 0; i < n; i++) {
        int num = s[i] - 'a';
        
        if (last[num] > first[num] + 1) {
            curr = prefix[last[num] - 1] - prefix[first[num]];
            res.push_back(curr);
            last[num] = -1;
        }
    }
    return res;
}
};