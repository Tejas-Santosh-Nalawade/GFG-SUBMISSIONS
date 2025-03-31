//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &str) {
        int i = 0, j = 0, k = 0; 
        int c = 0, r = 0; 
        unordered_map<int,int> m; 
        for (i = str.length() - 1; 
            i >= 0; 
            i--) { 
 
            if (m[str[i]] == 0) { 
                m[str[i]] = i; 
            } 
        } 
 
        i = 0; 
        k = m[str[i]]; 
 
        for (i = 0; i < str.length(); i++) { 
 
            if (i <= k) { 
                c = c + 1; 
                k = max(k, m[str[i]]); 
            } 
 
            else { 
                r = r + 1; 
                c = 1; 
                k = max(k, m[str[i]]); 
            } 
        } 
        if (c != 0) { 
            r = r + 1; 
        } 
        return r; 
    } 
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends