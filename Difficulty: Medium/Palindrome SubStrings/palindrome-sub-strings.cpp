//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
    int origSize = s.length();
        s = '$' + s + '@';
        string str = "";
        for(auto it:s){
            str+=it;
            str+='#';
        }
        str.pop_back();
        int n = str.length();
        int r = 0, c = 0;
        vector<int>lps(n, 0);
        for(int i=1;i<n;i++){
            if(i < r){
                int l= 2*c - i;
                lps[i] = min(lps[l], r-i);
            }
            while(str[i + lps[i] + 1] == str[i - lps[i] - 1]) lps[i]++;
            if(i+lps[i] > r){
                r = i + lps[i];
                c = i;
            }
        }
        int count =0;
        for(int i=0;i<n;i++) {
            count+= (lps[i]+1)/2;
        };
        return count - origSize;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends