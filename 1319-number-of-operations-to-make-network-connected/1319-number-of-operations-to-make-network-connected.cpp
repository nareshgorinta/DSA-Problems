class Solution {
public:
    int spanning(int src,vector<vector<int>> &adj,vector<int>&vis){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        pq.push({0,src});
        int cnt  = 0;
        while(!pq.empty()){

            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int val = it.first;

            if(vis[node] == 1) continue;

            vis[node] = 1;
            cnt+=1;

            for(auto neigh:adj[node]){
                int adjNode = neigh;
				if (!vis[adjNode]) {
					pq.push({val+1, adjNode});
                }
            }
        }
        return cnt - 1;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int  E = connections.size();

        vector<vector<int>> adj(n);


        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0);
        int val = 0;
        int group = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                group++;
                val+=spanning(i,adj,vis);
            }
        }

        int v=0;
        for(int o:vis){
            if(o==0) v++;
        }

        if((E-val) >= (group - 1)){
            return group -1;
        }
        return -1;
    }
};