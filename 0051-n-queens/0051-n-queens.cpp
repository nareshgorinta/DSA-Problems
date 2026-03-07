class Solution {
public:
    bool issafe(int i, int j, int n, vector<vector<string>>& vis) {
        for (int k = i - 1; k >= 0; k--) {
            if (vis[k][j] == "Q") return false;
        }
        for (int k = i - 1, l = j - 1; k >= 0 && l >= 0; l--, k--) {
            if (vis[k][l] == "Q") return false;
        }
        for (int k = i - 1, l = j + 1; k >= 0 && l < n; k--, l++) {
            if (vis[k][l] == "Q") return false;
        }
        return true;
    }

    // Change: Changed return type to void to ensure we explore everything
    void solve(int i, int n, vector<vector<string>>& vis, vector<vector<string>>& all_boards) {
        if (i == n) {
            vector<string> board;
            for (int row = 0; row < n; row++) {
                string s = "";
                for (int col = 0; col < n; col++) {
                    s += (vis[row][col] == "Q" ? 'Q' : '.');
                }
                board.push_back(s);
            }
            all_boards.push_back(board); // Found one! Store it and keep going.
            return;
        }

        for (int j = 0; j < n; j++) {
            if (issafe(i, j, n, vis)) {
                vis[i][j] = "Q";
                solve(i + 1, n, vis, all_boards); // Continue searching instead of returning
                vis[i][j] = "."; // Backtrack to try the next column
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vis(n, vector<string>(n, "."));
        vector<vector<string>> all_boards;
        solve(0, n, vis, all_boards);
        return all_boards;
    }
};