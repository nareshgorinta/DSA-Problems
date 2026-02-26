class Solution {
public:
    vector<int> parent, sz;

    int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    void unite(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb) return;

        if(sz[pa] < sz[pb]) swap(pa, pb);

        parent[pb] = pa;
        sz[pa] += sz[pb];
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        parent.resize(n*n);
        sz.assign(n*n,1);

        for(int i=0;i<n*n;i++) parent[i] = i;

        vector<int> dx = {-1,0,1,0};
        vector<int> dy = {0,-1,0,1};

        // Step 1: build DSU for all 1s
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int node = i*n + j;

                    for(int k=0;k<4;k++){
                        int X = i + dx[k];
                        int Y = j + dy[k];

                        if(X>=0 && Y>=0 && X<n && Y<n && grid[X][Y]==1){
                            unite(node, X*n + Y);
                        }
                    }
                }
            }
        }

        int ans = 0;

        // Step 2: try flipping each 0
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 0){
                    unordered_set<int> comps;
                    int sum = 1;

                    for(int k=0;k<4;k++){
                        int X = i + dx[k];
                        int Y = j + dy[k];

                        if(X>=0 && Y>=0 && X<n && Y<n && grid[X][Y]==1){
                            int root = find(X*n + Y);
                            if(!comps.count(root)){
                                sum += sz[root];
                                comps.insert(root);
                            }
                        }
                    }
                    ans = max(ans, sum);
                }
            }
        }

        // Step 3: edge case (all 1s)
        for(int i=0;i<n*n;i++){
            ans = max(ans, sz[find(i)]);
        }

        return ans;
    }
};