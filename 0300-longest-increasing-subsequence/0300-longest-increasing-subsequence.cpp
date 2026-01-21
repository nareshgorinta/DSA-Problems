class Solution {
public:
    int solve(int i,int val,vector<int>& nums,vector<vector<int>> &dp){
        if(i==nums.size()){
            return 0;
        }

        if(dp[i][val+1] != -1){
            return dp[i][val+1];
        }
        int pick = 0;
        if(val == -1 || nums[i] > nums[val]){
            pick = 1 + solve(i+1,i,nums,dp);
        }
        int nonpick = solve(i+1,val,nums,dp);
        dp[i][val+1] = max(pick,nonpick);
        return dp[i][val+1];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }
};