class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] != 0 || grid[n-1][n-1] != 0){
            return -1;
        }

        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        set<vector<int>> st;
        dist[0][0] = 1;
        st.insert({1,0,0});

        while(!st.empty()){
            auto it = *(st.begin());

            int i = it[1];
            int j = it[2];
            int dis = it[0];

            st.erase({dis,i,j});

            vector<int> dx = {-1,-1,-1, 0, 0, 1, 1, 1};
            vector<int> dy = {-1, 0, 1,-1, 1,-1, 0, 1};

            for(int k=0;k<8;k++){
                int X = i + dx[k];
                int Y = j + dy[k];

                if(X>= 0 && Y >= 0 && Y<n && X < n && dist[X][Y] > dis +1 && grid[X][Y] == 0){
                    dist[X][Y] = dis + 1;
                    st.insert({dist[X][Y],X,Y});
                }
            }
        }
        if(dist[n-1][n-1] == INT_MAX){
            return -1;
        }
        return dist[n-1][n-1];
    }
};