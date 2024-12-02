//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minChar(string& s) {
    int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        s += '#';
        s += t;
        
        int lps[2*n] = {0};
        int i=1;
        int len = 0;
        
        while(i<2*n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0) len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return ((n-1) - lps[2*n-1]);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends