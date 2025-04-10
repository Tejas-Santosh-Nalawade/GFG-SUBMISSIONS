//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class DisjointSet{
  public:
    vector<int> par,size;
    DisjointSet(int n){
        par.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
            size[i] = 1;
        }
    }
    
    int findParent(int u){
        if(par[u]==u) return u;
        return par[u] = findParent(par[u]);
    }
    
    void unionBySize(int u, int v){
        int uP = findParent(u);
        int vP = findParent(v);
        
        if(uP==vP) return;
        
        if(size[uP]>size[vP]){
            size[uP]+=size[vP];
            par[vP] = par[uP];
        }else{
            size[vP]+=size[uP];
            par[uP] = par[vP];
        }
        
    }
    
    
};
class Solution {
  public:
    int distance(vector<int> &a, vector<int> &b){
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
  
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int d = distance(houses[i],houses[j]);
                pq.push({d,i,j});
            }
        }
        
        int ans = 0;
        
        DisjointSet ds(n);
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int d = p[0];
            if(ds.findParent(p[1])!=ds.findParent(p[2])){
                ds.unionBySize(p[1],p[2]);
                ans+=d;
            }
        }
        
        return ans;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends