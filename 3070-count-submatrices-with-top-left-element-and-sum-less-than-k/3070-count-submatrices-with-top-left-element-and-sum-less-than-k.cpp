class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();


        vector<vector<int>> pre(n+1,vector<int>(m+1,0));

        int cnt  = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                pre[i][j] = grid[i-1][j-1] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];

                if(pre[i][j]  <= k){
                    cnt++;
                }
            }
        }
        return cnt;



        
    }
};