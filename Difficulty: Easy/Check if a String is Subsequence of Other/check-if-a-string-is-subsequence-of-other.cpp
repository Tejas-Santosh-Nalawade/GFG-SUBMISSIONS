class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        int m = s1.length(), n = s2.length();
        // Not possible to be subsequence as it contains more character
        if(m>n) return false;
        int i=0,j=0;
        
        while(i<m && j<n){
            if(s1[i] == s2[j]){
                i++;
            }
            j++;
        }
        return i==m;
    }
};