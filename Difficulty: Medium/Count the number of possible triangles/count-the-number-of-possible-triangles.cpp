//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int c = 0;
        
        if(n<3)
        {
            return 0;
        }
        
        for(int i = n-1;i>=2;i--)
        {
            int j = 0, k = i-1;
            
            while(j<k)
            {
                if(arr[j] + arr[k] > arr[i])
                {
                    c += (k-j);
                    k--;
                }
                else
                {
                   j++; 
                }
            }
        }
        return c;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends