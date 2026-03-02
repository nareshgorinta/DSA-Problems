class Solution {
public:
    int ans  = 0;
    int find(int a,vector<int>&parent){
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a],parent);
    }

    void Union(int a,int b,vector<int>&size,vector<int>&parent){
        int pa = find(a,parent);
        int pb = find(b,parent);
        if(pa == pb)return ;

        if(size[pa] < size[pb]){
            parent[pa] = pb;
            size[pb]+=size[pa];
            ans = max(ans,size[pb]);
        }else{
            parent[pb] = pa;
            size[pa]+=size[pb];
            ans = max(ans,size[pa]);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int>parent(m*n);
        vector<int>size(m*n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int u = m*i + j;
                parent[u] = u;
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // 1. Use 'm' (columns) to calculate 1D index
                int u = m * i + j; 
                
                if(grid[i][j] == 1){
                    // If the cell is land, the minimum maxArea is at least 1
                    ans = max(ans, 1); 

                    vector<int> dx = {-1, 0, 1, 0};
                    vector<int> dy = {0, 1, 0, -1};

                    for(int k=0; k<4; k++){
                        int X = i + dx[k];
                        int Y = j + dy[k];

                        // 2. Fixed boundary check (>= instead of >)
                        if(X < 0 || Y < 0 || X >= n || Y >= m){
                            continue;
                        }
                        
                        // 3. Check if the NEIGHBOR is also land before Union
                        if(grid[X][Y] == 1){
                            int v = m * X + Y; // Use 'm' here too
                            Union(u, v, size, parent);
                        }
                    }
                }
            }
        }
        return ans;
    }
};