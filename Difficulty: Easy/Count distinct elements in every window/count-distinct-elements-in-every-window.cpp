//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &a, int k) {
        unordered_map <int,int> m;
        vector <int> ans;
        int n=a.size();
        for(int i = 0;i < k;i++) m[a[i]]++;
        for(int i = 0;i < n-k;i++){
        ans.push_back(m.size());
        if(m[a[i]]-- == 1) m.erase(a[i]);
        m[a[i+k]]++;
}
ans.push_back(m.size());
return ans;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends