class Solution {
public:
    int solve(int i,int j,string &s,vector<vector<int>>&dp){
        if(i>=j){
            return true;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j] && solve(i+1,j-1,s,dp)){
            dp[i][j] = true;
            return dp[i][j];
        }
        dp[i][j]=false;
        return dp[i][j];
    }
    string longestPalindrome(string s) {
        int idx = -1;
        int maxLen = 0;
        int n = s.size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(i,j,s,dp)){
                    if(maxLen < j-i+1){
                        idx = i;
                        maxLen = j-i+1;
                    }
                }
            }
        }
        return s.substr(idx,maxLen);
    }
};