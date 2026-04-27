class Solution {
  public:
    int smallestSubstring(string s) {
    int n = s.length(), i = 0, j = 0, cnt = 0, min_len = INT_MAX;

    int freq[3] = {0};
    while (j < n)
    {
        freq[s[j] - '0']++;
        if (freq[s[j] - '0'] == 1)
            cnt++;

        if (cnt == 3)
        {
            while (freq[s[i] - '0'] > 1)
            {
                freq[s[i] - '0']--;
                i++;
            }

            min_len = min(min_len, j - i + 1);
            freq[s[i] - '0']--;
            i++;
            cnt--;
        }

        j++;
    }
    return (min_len == INT_MAX) ? -1 : min_len;
}

};
