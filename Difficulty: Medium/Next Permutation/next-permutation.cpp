//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
        void nextPermutation(vector<int>& arr) {
        int ls=arr[arr.size()-1], j=arr.size()-1,k=arr.size()-1;;
        while(arr[j]>=ls)
            ls=arr[j--];
        if(j==-1){
            reverse(arr.begin(),arr.end());
            return;
        }
        while(arr[k]<=arr[j]) k--;
        swap(arr[j],arr[k]);
        reverse(arr.begin()+j+1,arr.end());
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
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends