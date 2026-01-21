class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        // Each index has a map: diff -> length of sequence ending at i
        vector<unordered_map<int, int>> dp(n);
        int maxLen = 2; // Any two numbers form a sequence

        // Fill in the DP logic here
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                // dp[j][diff] might not exist yet
                int len = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                dp[i][diff] = max(dp[i][diff], len);
                maxLen = max(maxLen, dp[i][diff]);
            }
        }
        return maxLen;
    }
};