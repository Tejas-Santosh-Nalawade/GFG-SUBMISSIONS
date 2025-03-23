//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countWays(string &str) {
int m=1e9+7;

     int n=str.size();

     vector<long long int> dp(n+1,0);

     dp[0]=1;

     dp[1]=1;

     

     for(int i=2;i<=n;i++)

     {

         int ele=str[i-1]-'0';

         long long now=0;

         if(ele>0)

         {

             now+=dp[i-1];

         }

         

         int last=(str[i-2]-'0')*10+(str[i-1]-'0');

         if(last>=10 && last<=26)

             now+=dp[i-2];

             

        now%=m;

        dp[i]=now;

     }

     

     return dp[n];

 }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string digits;
        getline(cin, digits);
        Solution obj;
        int ans = obj.countWays(digits);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends