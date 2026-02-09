class Solution {
  public:
    int findKRotation(vector<int> &arr) {
       int n=arr.size();
       int ele=*min_element(arr.begin(),arr.end());
       for(int i=0; i<n; i++){
           if(ele==arr[i]){
               return i;
           }
       }
       
       return 0;
    }
};
