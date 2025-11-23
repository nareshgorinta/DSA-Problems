class Solution {
public:
    int solve(int i,int r,vector<int>&nums,vector<vector<int>>&dp){
        // base case

        int n = nums.size();

        if(i==n){
            if(r==0){
                return 0;
            }else{
                return INT_MIN;
            }
        }
        if(dp[i][r] != -1){
            return dp[i][r];
        }
        int take = nums[i] + solve(i+1,((r+nums[i])%3)%3,nums,dp);

        int nontake = solve(i+1,r,nums,dp);
        

        return dp[i][r]=max(nontake,take);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        return solve(0,0,nums,dp);
    }
};