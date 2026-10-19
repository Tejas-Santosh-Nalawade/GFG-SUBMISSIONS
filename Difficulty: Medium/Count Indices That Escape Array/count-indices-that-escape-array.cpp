class Solution {
  public:
    int count=0;
    void dfs(unordered_map<int,vector<int>>&graph,int node){
        count++;
        for(int i:graph[node]){
            dfs(graph,i);
        }
        return;
    }
    int goodIndices(vector<int> &arr) {
        count=0;
        int n=arr.size();
        vector<int>adj(n);
        unordered_map<int,vector<int>>graph;
        for(int i=0;i<n;i++){
            adj[i]=(arr[i]+i>=n or arr[i]+i<0)?n:arr[i]+i;

        }
        for(int i=0;i<n;i++){
            graph[adj[i]].push_back(i);
        }
        dfs(graph,n);

        return count-1;




    }
};