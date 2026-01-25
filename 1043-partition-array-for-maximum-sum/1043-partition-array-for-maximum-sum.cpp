class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);   // dp[n] = 0 already

        for (int i = n - 1; i >= 0; i--) {
            int maxi = 0;
            int ans = 0;

            for (int len = 1; len <= k && i + len - 1 < n; len++) {
                maxi = max(maxi, arr[i + len - 1]);
                ans = max(ans, maxi * len + dp[i + len]);
            }

            dp[i] = ans;
        }

        return dp[0];
    }
};
