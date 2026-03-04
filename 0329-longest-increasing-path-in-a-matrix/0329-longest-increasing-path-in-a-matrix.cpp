

class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        dp[i][j] = 1;

        vector<int>dx={-1,0,1,0};
        vector<int>dy={0,1,0,-1};

        for(int k=0;k<4;k++){
            int X = i + dx[k];
            int Y = j + dy[k];

            if(X>=0 && X<n && Y>=0 && Y<m){
                if(matrix[X][Y] > matrix[i][j]){
                    dp[i][j] = max(dp[i][j] , 1 + solve(X,Y,dp,matrix));
                }
            }
        }

        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j] == -1){
                    ans = max(ans, solve(i,j,dp,matrix));
                }
            }
        }

        

        return ans;
    }
};