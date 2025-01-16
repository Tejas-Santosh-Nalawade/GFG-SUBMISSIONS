//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &arr) {
        unordered_map<int, int> prefixSumMap;
        int prefix_sum = 0, max_length = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            arr[i] = (arr[i] == 0) ? -1 : 1;
            
            
            prefix_sum += arr[i];
            if (prefix_sum == 0) {
                max_length = i + 1;
            }
            if (prefixSumMap.find(prefix_sum) != prefixSumMap.end()) {
                max_length = max(max_length, i - prefixSumMap[prefix_sum]);
            } else {
              
                prefixSumMap[prefix_sum] = i;
            }
        }
        
        return max_length;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends