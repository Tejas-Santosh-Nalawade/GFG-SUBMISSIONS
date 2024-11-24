//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
       int maxx= arr[0],minn = arr[0], prd = arr[0];
        for (int i = 1; i < arr.size(); i++) {
        
             if(arr[i] < 0){
                swap(minn, maxx);
            }else if(arr[i] == 0){
                minn = maxx = 1;
            }
            
            minn = minn * arr[i];
            minn = min(minn, arr[i]);
            
            maxx = maxx * arr[i];
            maxx = max(arr[i], maxx);
            
            prd = max(prd, maxx);
        }
        
        return prd;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends