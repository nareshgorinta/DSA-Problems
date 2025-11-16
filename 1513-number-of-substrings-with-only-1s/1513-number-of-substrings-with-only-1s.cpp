class Solution {
public:
    int numSub(string s) {
        long long cnt = 0;
        long long ans = 0;
        const long long mod = 1000000007;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                cnt++;
            } else {
                if (cnt != 0) {
                    ans = (ans + (cnt * (cnt + 1) / 2) % mod) % mod;
                    cnt = 0;
                }
            }
        }

        if (cnt != 0) {
            ans = (ans + (cnt * (cnt + 1) / 2) % mod) % mod;
        }

        return ans % mod;
    }
};
