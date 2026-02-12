class Solution {
public:
    void dfs(int v,vector<bool>&vis,vector<vector<int>>& isConnected){
        int V = isConnected.size();
        vis[v] = true;
        for(int i=0;i<V;i++){
            if(isConnected[v][i] && !vis[i]){
                dfs(i,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        int cnt =0;
        vector<bool>vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,isConnected);
            }
        }
        return cnt;
    }
};