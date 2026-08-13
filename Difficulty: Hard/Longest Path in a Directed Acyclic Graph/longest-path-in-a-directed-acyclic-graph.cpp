class Solution {
    protected:
    const int inf= INT_MIN;
    private:
    void topo(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[]){
        vis[node]=1;
        for(auto i: adj[node]){
            
            if(!vis[i.first]){
                topo(i.first, vis, st, adj);
            }
        }
        st.push(node);
    }
    public:
    vector<int> maxDistance(int v, int src, vector<vector<int>> &edges) {
      vector<int> vis(v, 0);
        vector<pair<int, int>> adj[v];
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            int wt= i[2];
            adj[u].push_back({v, wt});
        }
        stack<int> st;
     for(int i=0; i<v; i++){
         if(!vis[i]){
             topo(i, vis, st, adj);
         }
     }  
     vector<int> dist(v, inf);
     dist[src]= 0;
     while(!st.empty()){
         
         int top= st.top();
         st.pop();
         for(auto i: adj[top]){
             int u= top;
             int v= i.first;
             int wt= i.second;
             if(dist[u]==inf)continue;
             if(dist[u] + wt > dist[v]){
                 dist[v]= dist[u] + wt;
             }
         }
     }
     return dist;
    }
};