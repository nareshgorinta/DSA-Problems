class Solution {
public:

    void dfs(int i,int j,vector<vector<int>>& grid){
        grid[i][j] = 0;

        vector<int>dx = { -1, 0 , 1, 0};
        vector<int>dy = {0, 1, 0, -1};

        for(int k=0;k<4;k++){
            int X = i + dx[k];
            int Y = j + dy[k];

            if(X>= 0 && Y>=0 && X < grid.size() && Y < grid[0].size()){
                if(grid[X][Y] == 1){
                    dfs(X,Y,grid);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        int cnt  = 0;

        for(int i=0;i<r;i++){
            if(grid[i][0] == 1){
                dfs(i,0,grid);
            }
        }
        for(int j=0;j<c;j++){
            if(grid[0][j] == 1){
                dfs(0,j,grid);
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};