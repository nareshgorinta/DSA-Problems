class Solution {
public:
    const int MOD = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> p(n, vector<int>(m));
        
        long long current_prod = 1;

        // Step 1: Fill p with prefix products (product of all elements before current)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                p[i][j] = current_prod;
                current_prod = (current_prod * (grid[i][j] % MOD)) % MOD;
            }
        }

        // Step 2: Multiply by suffix products (product of all elements after current)
        current_prod = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                p[i][j] = (p[i][j] * current_prod) % MOD;
                current_prod = (current_prod * (grid[i][j] % MOD)) % MOD;
            }
        }

        return p;
    }
};
