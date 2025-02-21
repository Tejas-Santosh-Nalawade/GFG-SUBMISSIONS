//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int maxLength(string str) {
int ans = 0, n = str.length();
        stack<int> s;
        // let say dp[i] repreesent the longest valid substring ending at i i.e string having str[i] as its last character
        int dp[n];
        for(int i = 0; i<n; i++){
            if(str[i]=='('){
                s.push(i);
                dp[i] = 0;
            }
            else{
                if(!s.empty()){
                    int j = s.top();
                    s.pop();
                    int before_streak = 0;
                    if(j-1 >= 0) before_streak = dp[j-1];// to address ()().. to add any before streak
                    ans = max(ans,i-j+1+before_streak); // the range of i-j is entirely valid
                    // ((())) kind of things are addressed by i-j+1
                    dp[i] = i-j+1+before_streak;
                }
                else{
                   dp[i] = 0; 
                }
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends