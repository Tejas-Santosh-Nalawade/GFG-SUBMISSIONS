class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
    int n = arr.size();
    map<int, int> freqMap;

    for (int val : arr) {
        freqMap[val]++;
    }

    for (auto p : freqMap) {
        int val = p.first;
        int freq = p.second;

        if (freq == 0) continue;

        for (int i = 1; i < k; i++) {
            int nextVal = val + i;
            if (freqMap[nextVal] < freq) {
                return false;
            }
            freqMap[nextVal] -= freq;
        }
    }

    return true;
    }
};