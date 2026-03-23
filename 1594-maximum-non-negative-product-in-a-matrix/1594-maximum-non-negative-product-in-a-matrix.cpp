class Solution {
public:
    const long long MOD = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Use long long to prevent overflow during comparisons
        // first = min product, second = max product
        vector<vector<pair<long long, long long>>> dp(n, vector<pair<long long, long long>>(m));
        
        dp[0][0] = {grid[0][0], grid[0][0]};

        // Initialize first column
        for(int i = 1; i < n; i++) {
            long long val = dp[i-1][0].first * grid[i][0];
            dp[i][0] = {val, val};
        }


        for(int j = 1; j < m; j++) {
            long long val = dp[0][j-1].first * grid[0][j];
            dp[0][j] = {val, val};
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                long long cur = grid[i][j];
              
                long long a = cur * dp[i][j-1].first;
                long long b = cur * dp[i][j-1].second;
                long long c = cur * dp[i-1][j].first;
                long long d = cur * dp[i-1][j].second;
                
                dp[i][j].first = min({a, b, c, d});
                dp[i][j].second = max({a, b, c, d});
            }
        }

        long long maxProd = dp[n-1][m-1].second;
        
        
        return (maxProd < 0) ? -1 : (maxProd % MOD);
    }
};
