class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int count = 0;
        for(int val : arr){
            if(val <= x){
                count++;
            }
        }
        return count;
    }
};