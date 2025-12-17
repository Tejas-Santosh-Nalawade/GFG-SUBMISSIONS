class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>>res;
        res.push_back(arr[0]);
        
        for(int i=1; i<n; i++){
            vector<int>&last = res.back();
            vector<int>&current = arr[i];
            
            if(current[0] <= last[1]){
                last[1] = max(last[1], current[1]);
            }
            else{
                 res.push_back(current);
            }  
        }
        return res;
    }
};