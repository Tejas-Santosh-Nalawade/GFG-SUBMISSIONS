//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minJumps(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j <= i + arr[i] && j < n; j++) {
            if (dp[j] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[j]);
            }
        }
    }
    if (dp[0] == INT_MAX)
        return -1;

    return dp[0];
}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends