//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int maxi=0;
        stack<int> s;
        int n=prices.size();
        s.push(prices[n-1]);
        for(int i=n-2;i>=0;i--){
            
            if(prices[i]>s.top()){
                s.push(prices[i]);
            }else{
                s.push(s.top());
            }
            
        }
        for(int i=0;i<prices.size();i++){
            maxi=max(maxi,s.top()-prices[i]);
            s.pop();
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends