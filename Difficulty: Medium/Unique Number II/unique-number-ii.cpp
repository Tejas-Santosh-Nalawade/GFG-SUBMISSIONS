//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
 int xorVal = 0;
    for (auto i : arr) {
        xorVal = i ^ xorVal;
    }
    xorVal &= -xorVal;

    vector<int> res(2, 0);
    
    for (int num : arr) {
        if ((num & xorVal) == 0) { 
            res[0] ^= num;
        }
        else { 
            res[1] ^= num;
        }
    }
    if (res[0] > res[1]) {
        swap(res[0], res[1]);
    }

    return res;
}
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends