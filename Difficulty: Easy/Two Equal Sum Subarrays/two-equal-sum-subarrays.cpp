class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        int total = 0;
        for (int i = 0; i < arr.size(); i++)
            total += arr[i];

        int leftSum = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            leftSum += arr[i];
            int rightSum = total - leftSum;

            if (leftSum == rightSum)
                return true;
        }

        return false;
    }
};
