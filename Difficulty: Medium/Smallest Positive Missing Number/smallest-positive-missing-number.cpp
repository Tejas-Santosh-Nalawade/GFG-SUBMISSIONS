//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
int missingNumber(vector<int> &arr) {
        int maxi=*max_element(arr.begin(),arr.end());
        if(maxi<=0){
            return 1;
        }
        unordered_set<int>st(arr.begin(),arr.end());
        for(int i=1;i<=maxi;i++){
            if(st.find(i)==st.end()){
                return i;
            }
        }
        return maxi+1;
    }
};

//{ Driver Code Starts.

// int missingNumber(int arr[], int n);

int main() {

    // taking testcases
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
        int result = ob.missingNumber(arr);
        cout << result << "\n";
    }
    return 0;
}
// } Driver Code Ends