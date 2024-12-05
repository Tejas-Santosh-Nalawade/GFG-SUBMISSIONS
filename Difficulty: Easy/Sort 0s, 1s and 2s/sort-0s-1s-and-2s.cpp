//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero = 0;
        int nonZero = 1;
        int n = arr.size();
        
        while(nonZero < n){
            if(arr[zero] == 0){
                zero++;
                nonZero++;
            }
            
            else if(arr[nonZero] != 0) nonZero++;
            
            else{
                swap(arr[zero],arr[nonZero]);
            }
        }
        
        int one = 0;
        int notOne = 1;
        
        while(arr[one] == 0){
            one++;
            notOne++;
        }
        
        while(notOne < n){
            if(arr[one] == 1){
                one++;
                notOne++;
            }
            else if(arr[notOne] != 1) notOne++;
            else{
                swap(arr[one],arr[notOne]);
            }
        }
    }
};;

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends