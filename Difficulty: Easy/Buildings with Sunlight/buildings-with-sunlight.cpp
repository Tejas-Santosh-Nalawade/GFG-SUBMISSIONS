class Solution {
  public:
    int visibleBuildings(vector<int>& arr) {
        int count=0;
        int maximum_val = arr[0];
        for(int i=0; i<arr.size(); i++){
            if(arr[i] >= maximum_val){
                count++;
            }
            maximum_val = max(arr[i],maximum_val);
        }
        return count;
        
    }
};