//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
  int left = 0, max_len = 0, best_start = 0;
        deque<int> min_deque, max_deque;

        for (int right = 0; right < arr.size(); ++right) {
            while (!max_deque.empty() && arr[max_deque.back()] < arr[right]) {
                max_deque.pop_back();
            }
            max_deque.push_back(right);

            while (!min_deque.empty() && arr[min_deque.back()] > arr[right]) {
                min_deque.pop_back();
            }
            min_deque.push_back(right);

            while (arr[max_deque.front()] - arr[min_deque.front()] > x) {
                left++;
                if (!max_deque.empty() && max_deque.front() < left) {
                    max_deque.pop_front();
                }
                if (!min_deque.empty() && min_deque.front() < left) {
                    min_deque.pop_front();
                }
            }

            if (right - left + 1 > max_len) {
                max_len = right - left + 1;
                best_start = left;
            }
        }

        return vector<int>(arr.begin() + best_start, arr.begin() + best_start + max_len);
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends