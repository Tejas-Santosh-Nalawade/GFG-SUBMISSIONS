//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int K) {
        int ln=0,sum=0;
        int N=arr.size();
        map<int,int>m;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
            if(sum==K)ln=max(i+1,ln);
            if(m.find(sum)==m.end())m[sum]=i;
            if(m.find(sum-K)!=m.end())ln=max(ln,i-m[sum-K]);
        }
        return ln;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends