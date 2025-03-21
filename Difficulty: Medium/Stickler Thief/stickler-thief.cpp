//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int findMaxSum(vector<int>& arr) {
        int n= arr.size();
       if(n==0) return 0;
       if(n==1) return arr[0];
       
       int v1 = arr[0];
       int v2 = max(v1, arr[1]);
       
       for(int i=2; i<n; i++){
           int temp = v2;
           v2 = max(v2, v1+arr[i]);
           v1 = temp;
       }
       
       return v2;
        
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends