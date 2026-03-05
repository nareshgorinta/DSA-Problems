class Solution {
public:
    vector<vector<int>>arr;
    int dfs(int i,int des,vector<vector<int>>&graph,vector<int>&vis,vector<int>&ans){
        int n  = graph.size();
        if(i == des){
            ans.push_back(des);
            arr.push_back(ans);
            ans.pop_back();
            return 1;
        }

        vis[i] = 1;
        ans.push_back(i);
        int s  = 0;
        for(int j:graph[i]){
            if(!vis[j]){
                s+=dfs(j,des,graph,vis,ans);
            }
        }
        vis[i] = 0;
        ans.pop_back();
        return s;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>ans;
        vector<int>vis(n,0);
        dfs(0,n-1,graph,vis,ans);
        return arr;
    }
};