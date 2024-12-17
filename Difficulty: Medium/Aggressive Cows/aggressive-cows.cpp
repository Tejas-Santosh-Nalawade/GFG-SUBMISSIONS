//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
bool cando(int mid,vector<int> &stall,int cows){

        int f=stall[0];int cnt=1;

        for(int i=1;i<stall.size();i++){

            if(stall[i]-f>=mid){

                cnt++;f=stall[i];

            }

            if(cnt==cows) return true;

        }

        return false;

    }
    int aggressiveCows(vector<int> &stalls, int k) {

        int l=1;
        int ans=0;
       int n=stalls.size(); 
        sort(stalls.begin(),stalls.end());
        int h=stalls[n-1]-stalls[0];

        while(l<=h){

            int mid=(l+h)/2;

            if(cando(mid,stalls,k)){

                ans=mid;

                l=mid+1;

            }

            else{

                h=mid-1;

            }

        }

        return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends