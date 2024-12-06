//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        // Temporary arrays to hold halves
        vector<int> leftArr(n1), rightArr(n2);

        // Copy data to the temporary arrays
        for (int i = 0; i < n1; i++) 
            leftArr[i] = arr[left + i];
        for (int j = 0; j < n2; j++) 
            rightArr[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left, inversions = 0;

        // Merge the arrays while counting inversions
        while (i < n1 && j < n2) {
            if (leftArr[i] <= rightArr[j]) {
                arr[k++] = leftArr[i++];
            } else {
                arr[k++] = rightArr[j++];
                inversions += (n1 - i);
            }
        }

        while (i < n1) arr[k++] = leftArr[i++];
        while (j < n2) arr[k++] = rightArr[j++];

        return inversions;
    }

    int mergeSortAndCount(vector<int>& arr, int left, int right) {
        int inversions = 0;

        if (left < right) {
            int mid = left + (right - left) / 2;

            // Count inversions in left half
            inversions += mergeSortAndCount(arr, left, mid);

            // Count inversions in right half
            inversions += mergeSortAndCount(arr, mid + 1, right);

            // Count cross-inversions and merge halves
            inversions += mergeAndCount(arr, left, mid, right);
        }

        return inversions;
    }

    int inversionCount(vector<int>& arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n;
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);
        Solution obj;
        cout << obj.inversionCount(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends