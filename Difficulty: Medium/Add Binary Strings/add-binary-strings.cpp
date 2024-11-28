//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
string addBinary(string A, string B)
	{
	    int carry = 0;
	    reverse(A.begin(), A.end());
	    reverse(B.begin(), B.end());
	    
	    int n = A.length();
	    int m = B.length();
	    
	    int i = 0, j = 0;
	    string ans = "";
	    while(i < n || j < m)
	    {
	        int digit1 = 0;
	        int digit2 = 0;
	        if(i < n)
	        {
	            digit1 = A[i] - '0';
	            i++;
	        }
	        if(j < m)
	        {
	            digit2 = B[j] - '0';
	            j++;
	        }
	        
	        int result = digit1 + digit2 + carry;
	        carry = result / 2;
	        result = result % 2;
	        
	        ans.push_back(result + '0');
	    }
	    if(carry == 1)
	    {
	        ans.push_back(carry + '0');
	    }
	    else
	    {
	        int i = ans.length() - 1;
	        while(i >= 1 && ans[i] == '0')
	        {
	            ans.pop_back();
	            i--;
	        }
	    }
	    reverse(ans.begin(), ans.end());
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends