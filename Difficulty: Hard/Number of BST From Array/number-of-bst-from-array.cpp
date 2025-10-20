class Solution {
  public:
    
    vector<int>computeFact(int num){
        vector<int> fact(num+1);
        fact[0] = 1;
        for(int i=1; i<=num; i++){
            fact[i] = fact[i-1] * i;
        }
        return fact;
    }
    
    // Created this catalan for precompute the factorials 
    int catalan(int n, vector<int>&fact){
        return fact[2*n] / (fact[n] * fact[n+1]);
    }
  
    vector<int> countBSTs(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>>sorted;
        // Pair of the index and its value 
        for(int i=0;i<n; i++){
            sorted.push_back({arr[i],i});
        }
        // Sorted it value
        sort(sorted.begin(),sorted.end());
        
        // Precompute the factorial up to 2*n
        
        vector<int>fact = computeFact(2*n);
        
        vector<int>numsBSTs(n);
        
        // Counting each element as a root 
        
        for(int i=0; i<n; i++){
            int j = sorted[i][1];
            
            numsBSTs[j] = catalan(i,fact) * catalan(n-i-1,fact);
            
            
        }
        return numsBSTs;
        
    }
};