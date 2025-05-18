//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int ans = 0;
        vector<vector<int>> arr;

        for (int i = 0; i < start.size(); i++)
        {
            arr.push_back({finish[i], start[i]});
        }
        sort(arr.begin(), arr.end());
        int finishtime = -1;

        for (int i = 0; i < arr.size(); i++)
        {
            vector<int> activity = arr[i];
            if (activity[1] > finishtime)
            {
                finishtime = activity[0];
                ans++;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends