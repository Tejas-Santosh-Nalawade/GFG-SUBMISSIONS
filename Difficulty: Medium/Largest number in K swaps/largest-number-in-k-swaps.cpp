//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    string findMax(string &s, int k) {
    if (k == 0) {
        return s;
    }
    int n = s.size();
    string ans = s;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] < s[j]) {
                swap(s[i], s[j]);
                ans = max(ans, findMax(s, k - 1));
                swap(s[i], s[j]);
            }
        }
    }

    return ans;
}

string findMaximumNum(string s, int k) {
    return findMax(s, k);
}

};


//{ Driver Code Starts.

int main() {
    int t, k;
    string str;

    cin >> t;
    while (t--) {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends