class Solution {
public:
    int solve(int i,vector<int> & nums,vector<int>&dp){
        if(i>=nums.size()){
            return INT_MAX;;
        }
        if(i==nums.size()-1){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int k = nums[i];
        int ans = nums.size();
        for(int j=1;j<=k;j++){
            ans = min(ans,1+solve(j+i,nums,dp));
        }

        dp[i]=ans;
        return dp[i];
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,nums,dp);
    }
};