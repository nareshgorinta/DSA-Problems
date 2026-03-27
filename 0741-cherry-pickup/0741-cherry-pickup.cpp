class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(int r1, int c1, int c2, vector<vector<int>>& grid) {
        int r2 = r1 + c1 - c2;

        if (r1 >= n || c1 >= n || c2 >= n || r2 >= n)
            return INT_MIN;

        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (r1 == n-1 && c1 == n-1)
            return grid[r1][c1];

        if (dp[r1][c1][c2] != -1)
            return dp[r1][c1][c2];

        int cherries = 0;

        if (r1 == r2 && c1 == c2)
            cherries = grid[r1][c1];
        else
            cherries = grid[r1][c1] + grid[r2][c2];

        int ans = max({
            solve(r1+1, c1, c2, grid),       // down, down
            solve(r1, c1+1, c2+1, grid),     // right, right
            solve(r1+1, c1, c2+1, grid),     // down, right
            solve(r1, c1+1, c2, grid)        // right, down
        });

        if (ans == INT_MIN)
            return dp[r1][c1][c2] = INT_MIN;

        return dp[r1][c1][c2] = ans + cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1)));

        int ans = solve(0, 0, 0, grid);
        return max(0, ans);
    }
};