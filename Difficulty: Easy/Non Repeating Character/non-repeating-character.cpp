//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the first non-repeating character in a string.
   char nonRepeatingChar(string S)
   {
      //Your code here
      
      int count[256]={0};
       for(int i=0;i<S.length();i++)
           count[S[i]]++;
       for(int i=0;i<S.length();i++)
       {
           if(count[S[i]]==1){
                return S[i];}
       }
      return '$';
   }


};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;

    while (T--) {

        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonRepeatingChar(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends