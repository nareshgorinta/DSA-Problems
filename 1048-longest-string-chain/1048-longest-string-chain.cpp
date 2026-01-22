class Solution {
public:
    bool check(string &s1, string &s2) {
        // s1 should be predecessor of s2
        if (s1.size() + 1 != s2.size()) return false;

        int i = 0, j = 0;
        while (i < (int)s1.size() && j < (int)s2.size()) {
            if (s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                j++; // skip one extra char in s2
            }
        }
        return (i == (int)s1.size());
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // sort by length (important for this DP to work correctly)
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1), parent(n, -1);

        int maxi = 1, lastindex = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (check(words[j], words[i])) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }

            if (dp[i] > maxi) {
                maxi = dp[i];
                lastindex = i;
            }
        }

        return maxi;
    }
};
