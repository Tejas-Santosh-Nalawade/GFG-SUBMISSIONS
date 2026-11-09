class Solution {
  public:
    int getCount(string &s, int k) {
  unordered_map<char, int> countGroup;

        char prevChar;

        int ans = 0;

        for (auto i : s) {
            if (prevChar != i) {
                countGroup[i]++;
                prevChar = i;
            }
        }

        for (auto i : countGroup) {
            if (i.second == k) {
                ans++;
            }
        }

        return ans;
    }
};
