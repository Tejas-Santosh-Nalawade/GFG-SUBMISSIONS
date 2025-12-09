class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        vector<int>ans;
        
        for(int i=0; i<arr.size(); i++){
            int idx = abs(arr[i]) - 1;
            
            if(arr[idx] > 0 ){
                arr[idx] = -arr[idx];
            }
            else{
                ans.push_back(abs(arr[i]));
            }
        }
        return ans;
        
        
    }
};