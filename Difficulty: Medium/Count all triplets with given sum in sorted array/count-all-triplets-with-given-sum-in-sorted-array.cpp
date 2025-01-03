//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int n = arr.size();
        int count = 0;
        unordered_map<int,int>mp;
        for(int j = 1;j< n;j++)
        {
            mp[arr[j]]++;
        }
        for(int i = 1;i<n-1;i++)
        { mp[arr[i]] --;
            for(int j = i-1;j>=0;j--)
            {
                int pairsum = arr[i] + arr[j];
                if(mp.find(target - pairsum) != mp.end())
                count += mp[target - pairsum];
            }
          
            
        }
        return count;
        
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends