class Solution {
public:
    bool solve(int i,int j,string &s,string &p,vector<int>&pre, vector<vector<int>>& dp){
        int n = s.length();
        int m = p.length();

        if(dp[i][j] != -1) return dp[i][j];

        if(i == n && j == m){
            return dp[i][j] = true;
        }

        if(i == n){
            for(int k = j; k < m; k++){
                if(p[k] != '*') return dp[i][j] = false;
            }
            return dp[i][j] = true;
        }

        if(i >= n || j >= m){
            return dp[i][j] = false;
        }

        if(p[j] != '?' && p[j] != '*'){
            if(p[j] != s[i]){
                return dp[i][j] = false;
            }
            return dp[i][j] = solve(i+1,j+1,s,p,pre,dp);
        }

        if(p[j] == '?'){
            return dp[i][j] = solve(i+1,j+1,s,p,pre,dp);
        }

        // ⭐ FIXED: optimized '*' handling (no loop)
        bool ans = solve(i, j+1, s, p, pre, dp) || solve(i+1, j, s, p, pre, dp);

        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<int>pre(m,0);
        for(int i=m-2;i>=0;i--){
            if(p[i+1] == '*'){
                pre[i] = pre[i+1] + 1;
            }else{
                pre[i] = pre[i+1];
            }
        }

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        return solve(0,0,s,p,pre,dp);
    }
};