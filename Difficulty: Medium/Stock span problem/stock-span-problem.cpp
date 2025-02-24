//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> v;
        int n=arr.size();
       stack<pair<int,int>>st;
       for(int i=0;i<n;i++){
           
           if(st.size()==0) v.push_back(-1);
           else if(st.size()>0 && st.top().first > arr[i])
                   v.push_back(st.top().second);
           else if(st.size()>0 && st.top().first <= arr[i])
           {
               while(st.size()>0 && st.top().first <= arr[i])
                      st.pop();
            if(st.size() == 0) v.push_back(-1);
            else v.push_back(st.top().second);
           } 
           st.push({arr[i],i});
       }
       for(int i=0;i<v.size();i++)
           v[i] = i - v[i];
       return v;
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
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends