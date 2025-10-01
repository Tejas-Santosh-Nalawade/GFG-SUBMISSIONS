class Solution {
  public:
void permuteRec(vector<int>& arr, int l, int r, set<vector<int>>& uniqueSet) {
    if (l == r) {
        uniqueSet.insert(arr);  
        return;
    }

    for (int i = l; i <= r; i++) {
        swap(arr[l], arr[i]);
        permuteRec(arr, l + 1, r, uniqueSet);
        swap(arr[l], arr[i]); 
    }
}

vector<vector<int>> uniquePerms(vector<int>& arr) {
    set<vector<int>> uniqueSet;
    permuteRec(arr, 0, arr.size() - 1, uniqueSet);

    vector<vector<int>> result(uniqueSet.begin(), uniqueSet.end());
    return result;
}

};