class Solution {
  public:
class manacher {
public:
    vector<int> p;

    string ms;
    manacher(string &s) {
        ms = "@";

        for (char c : s) {
            ms += "#";
            ms += c;
        }

        ms += "#$";
        runManacher();
    }

    void runManacher() {
        int n = ms.size();

        p.assign(n, 0);

        int l = 0;
        int r = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mirror = r + l - i;

            p[i] = max(0, min(r - i, p[mirror]));
            while (ms[i + 1 + p[i]] == ms[i - 1 - p[i]]) {
                ++p[i];
            }
            if (i + p[i] > r) {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }
    int getLongest(int cen, int odd) {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }
    bool check(int l, int r) {
        int len = r - l + 1;
        int center = (r + l) / 2;
        int isOdd = len % 2;
        return len <= getLongest(center, isOdd);
    }
};
int countPS(string& s) {
    manacher m(s);

    int total = 0;

    for (int i = 0; i < m.p.size(); ++i) {
        total += (m.p[i] + 1) / 2;
    }
    return total - s.length();
}
};