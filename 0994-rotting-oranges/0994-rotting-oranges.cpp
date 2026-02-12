class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // Step 1: Push all rotten oranges & count fresh
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        // No fresh oranges → no time needed
        if(fresh == 0) return 0;

        int time = 0;

        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};

        // Step 2: BFS
        while(!q.empty()){

            int size = q.size();
            bool rottenThisMinute = false;

            for(int k=0;k<size;k++){
                auto it = q.front();
                q.pop();

                int x = it.first;
                int y = it.second;

                // Check 4 directions
                for(int d=0; d<4; d++){
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                        rottenThisMinute = true;
                    }
                }
            }

            if(rottenThisMinute) time++;
        }

        // Step 3: Check if all became rotten
        return fresh == 0 ? time : -1;
    }
};
