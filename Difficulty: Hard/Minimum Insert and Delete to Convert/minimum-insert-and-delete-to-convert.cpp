class Solution {
public:
    int minInsAndDel(vector<int>& a, vector<int>& b) {
        unordered_set<int> valuesInB(b.begin(), b.end());
        vector<int> lis;

        for (int value : a) {
            if (!valuesInB.count(value))
                continue;

            auto pos = lower_bound(lis.begin(), lis.end(), value);

            if (pos == lis.end())
                lis.push_back(value);
            else
                *pos = value;
        }

        int lcsLength = lis.size();

        int deletions = a.size() - lcsLength;
        int insertions = b.size() - lcsLength;

        return deletions + insertions;
    }
};