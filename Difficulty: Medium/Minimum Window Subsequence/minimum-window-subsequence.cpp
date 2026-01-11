class Solution {
  public:
string minWindow(string &s1, string &s2) {
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> nextPos(n + 2, vector<int>(26, -1));

    for (int c = 0; c < 26; c++) {
        nextPos[n][c] = -1;
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int c = 0; c < 26; c++) {
            nextPos[i][c] = nextPos[i + 1][c];
        }
        nextPos[i][s1[i] - 'a'] = i;
    }

    string ans = "";
    int minLen = INT_MAX;

    for (int start = 0; start < n; start++) {
        if (s1[start] != s2[0]) continue;

        int idx = start;
        bool ok = true;

        for (int j = 0; j < m; j++) {
            if (idx == -1) {
                ok = false;
                break;
            }
            idx = nextPos[idx][s2[j] - 'a'];
            if (idx == -1) {
                ok = false;
                break;
            }   
            idx++; 
        }

        if (ok) {
            int endIdx = idx - 1;
            int len = endIdx - start + 1;
            if (len < minLen) {
                minLen = len;
                ans = s1.substr(start, len);
            }
        }
    }

    return ans;
}

};
