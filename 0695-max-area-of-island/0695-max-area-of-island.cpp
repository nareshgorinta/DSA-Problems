class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        grid[i][j] = 0;

        vector<int> dx ={ -1,0,1,0};
        vector<int>dy = { 0,1,0,-1};
        int cnt  = 1;
        for(int k=0;k<4;k++){
            int X = i + dx[k];
            int Y = j + dy[k];


            if( X>= 0 && Y>=0 && X<n && Y< m  && grid[X][Y] == 1){
                cnt+=dfs(X,Y,grid);
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans  = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    ans = max(ans,dfs(i,j,grid));
                }
            }
        }
        return ans;
    }
};