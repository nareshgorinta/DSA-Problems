class Solution {
public:
    bool ischeck(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    int solve(string &s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (ischeck(s, i, j)) return dp[i][j] = 0;

        int ans = INT_MAX;
        for (int k = i; k < j; k++) {
            if (ischeck(s, i, k)) {  // only cut when left part is palindrome
                int temp = 1 + solve(s, k + 1, j, dp);
                ans = min(ans, temp);
            }
        }
        return dp[i][j] = ans;
    }

    int minCut(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};
