class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<long long>>pre(n+1,vector<long long>(m+1,0));
        long long total = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                total+=grid[i-1][j-1];
                pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + grid[i-1][j-1];
            }
        }

        // horinotal cut

        for(int i=0;i<m-1;i++){
            int r2 = n-1;
            int c2 = i;
            long long sum = pre[r2+1][c2+1];
            if(total - 2*sum == 0){
                return true;
            }
        }
        //vertical cut
        for(int j=0;j<n-1;j++){
            int r2 = j;
            int c2 = m-1;
            long long sum = pre[r2 + 1][c2 + 1];
            if(total - 2*sum == 0){
                return true;
            }
        }


        return false;



        

    }
};