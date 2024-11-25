//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        int total = arr[0];
        int n=arr.size();
        int maxSum = arr[0] ,currMin = arr[0];
        int minSum = arr[0] ,currMax = arr[0];
        for(int i=1; i<n; i++){
            total += arr[i];

            currMin = min(currMin+arr[i],arr[i]);
            currMax = max(currMax+arr[i],arr[i]);

            maxSum = max(maxSum,currMax);
            minSum = min(minSum,currMin);
        }
        if(maxSum < 0) return maxSum;
        return max(total-minSum,maxSum);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends