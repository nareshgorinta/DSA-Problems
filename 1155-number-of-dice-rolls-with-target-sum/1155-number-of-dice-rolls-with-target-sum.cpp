class Solution {
public:
    int MOD = 1e9 + 7;
    int solve(int m,int n,int sum,vector<vector<int>>&dp){
        
        if(sum == 0 && n == 0){
            return 1;
        }
        if(n == 0){
            return 0;
        }
        if(dp[n][sum] != -1){
            return dp[n][sum];
        }
        int cnt  = 0;
        for(int i=1;i<=m;i++){
            if(i<=sum){
                cnt = (cnt + solve(m,n-1,sum-i,dp))% MOD;
            }
        }
        dp[n][sum] = cnt;
        
        return dp[n][sum];
    }
    
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(k,n,target,dp);
    }
};