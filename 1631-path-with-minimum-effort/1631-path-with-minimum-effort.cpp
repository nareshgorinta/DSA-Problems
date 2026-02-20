class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();


        vector<vector<int>>dist(r,vector<int>(c,INT_MAX));

        set<vector<int>> st;
        dist[0][0] = 0;
        st.insert({0,0,0});

        while(!st.empty()){
            auto it = *(st.begin());

            int i = it[1];
            int j = it[2];
            int dis = it[0];

            st.erase({dis,i,j});

            if(dis > dist[i][j]) continue;

            vector<int> dx = {-1,0,1,0};
            vector<int> dy = {0,1,0,-1};

            for(int k=0;k<4;k++){
                int X = i + dx[k];
                int Y = j + dy[k];

                
                if(X>= 0 && Y >= 0 && Y<c && X < r){
                    int val = abs(heights[i][j] - heights[X][Y]);

                    int a = dis;
                    if(val > a){
                        a = val;
                    }
                    if(dist[X][Y] > a){
                        dist[X][Y] = a;
                        st.insert({dist[X][Y],X,Y});
                    }
                    
                }
            }
        }
        return dist[r-1][c-1];
    }
};