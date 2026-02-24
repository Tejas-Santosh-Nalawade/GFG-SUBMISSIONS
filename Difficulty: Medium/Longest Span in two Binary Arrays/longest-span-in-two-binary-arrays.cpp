class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
    int n = a1.size();
    int maxLen = 0;
    
    unordered_map<int, int> diffMap;
    
    int prefixSum1 = 0, prefixSum2 = 0;
    
    for (int i = 0; i < n; i++) {
        prefixSum1 += a1[i];
        prefixSum2 += a2[i];
        
        int currentDiff = prefixSum1 - prefixSum2;

        if (currentDiff == 0) {
            maxLen = max(maxLen, i + 1);
        }
        
        else if (diffMap.find(currentDiff) != diffMap.end()) {
            maxLen = max(maxLen, i - diffMap[currentDiff]);
        } 
        else {
            
            diffMap[currentDiff] = i;
        }
    }
    
    return maxLen;
}
};