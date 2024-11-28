//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int maxOnes(vector<int>& arr, int k) {
        int left = 0;         
        int max_len = 0;       
        int zero_count = 0;   
        
        for (int right = 0; right < arr.size(); ++right) {
            if (arr[right] == 0) {
                zero_count++;
            }

  
            while (zero_count > k) {
                if (arr[left] == 0) {
                    zero_count--;
                }
                left++;
            }

            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
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
        int m;
        cin >> m;
        cin.ignore();

        Solution obj;
        int ans = obj.maxOnes(arr, m);
        cout << ans << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends