class Solution {
public:
    int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);

    dp[n-1] = 0;  // last index needs 0 jumps

    for(int i = n-2; i >= 0; i--) {
        for(int k = 1; k <= nums[i] && i + k < n; k++) {
            if(dp[i + k] != INT_MAX) {
                dp[i] = min(dp[i], 1 + dp[i + k]);
            }
        }
    }
    return dp[0];
}

};