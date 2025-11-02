#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // 0 = empty, 1 = wall, 2 = guard, 3 = guarded
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto &w : walls)
            grid[w[0]][w[1]] = 1;

        for (auto &g : guards)
            grid[g[0]][g[1]] = 2;
        
        int count = m * n - (guards.size() + walls.size());

        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        for (auto &g : guards) {
            int gr = g[0], gc = g[1];
            for (auto [dr, dc] : dirs) {
                int r = gr + dr, c = gc + dc;
                while (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] != 1 && grid[r][c] != 2) {
                    if (grid[r][c] == 0) {
                        grid[r][c] = 3;
                        count--;
                    }
                    r += dr;
                    c += dc;
                }
            }
        }

        return count;
    }
};
