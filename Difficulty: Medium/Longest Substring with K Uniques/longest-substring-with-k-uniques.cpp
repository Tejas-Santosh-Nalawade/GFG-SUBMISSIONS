class Solution {
  public:
    int longestKSubstr(string &s, int k) {
       int n = s.size();
       int i = 0,j = 0;
       int count = 0;
       
       int maximum = -1;
       
       vector<int> fre(26, 0);  
       
       while(j < n ){
           fre[s[j] - 'a']++;
           if (fre[s[j] - 'a'] == 1) count++;
           
           while(count > k){
               fre[s[i] - 'a']--;
               if (fre[s[i] - 'a'] == 0) count--;
               i++;
           }
            if (count == k) {
                maximum = max(maximum, j - i + 1);
            }

            j++;
       }
       return maximum;
       
        
    }
};