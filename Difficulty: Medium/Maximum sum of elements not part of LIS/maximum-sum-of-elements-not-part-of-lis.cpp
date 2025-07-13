class Solution {
  public:
    map<int, vector<int>> mp;
void insert(int val) {
    auto it = mp.lower_bound(val);

    int len = 1;
    int sum = val;

    if (it != mp.begin()) {
        auto prev = it;
        --prev;
        len = prev->second[0] + 1;
        sum = prev->second[1] + val;
    }

    vector<int> toerase;
    while (it != mp.end()) {
        if (it->second[0] > len) break;
        toerase.push_back(it->first);
        ++it;
    }

    for (int key : toerase) {
        mp.erase(key);
    }

    mp[val] = {len, sum};
}

int nonLisMaxSum(vector<int> &arr) {
    
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        insert(arr[i]);
    }

    auto last = --mp.end();
    int totalSum = accumulate(arr.begin(),arr.end(), 0);
    int lisSum = last->second[1];

    return totalSum - lisSum;
}

};