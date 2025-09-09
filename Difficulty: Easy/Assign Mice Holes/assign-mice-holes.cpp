class Solution {
  public:
int assignHole(vector<int>& mices, vector<int>& holes) {
    int n = mices.size();
    sort(mices.begin(), mices.end());
    sort(holes.begin(), holes.end());
    int max = 0; 
    for(int i = 0; i < n; ++i)
    {
        if (max < abs(mices[i] - holes[i]))
            max = abs(mices[i] - holes[i]);
    }
    return max;
}
};