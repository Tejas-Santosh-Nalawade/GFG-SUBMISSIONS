//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &S) {
    unordered_map<char,int>a;
    int n=S.length();

    int j=0,i=0,m=0;
   for(int i=0;i<n;i++)

    {
        a[S[i]]++;
        while(a[S[i]]>1)
        {         
            a[S[j]]--;

        j++;
        }
         m=max(m,i-j+1);
     }

    

   return m;

}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends