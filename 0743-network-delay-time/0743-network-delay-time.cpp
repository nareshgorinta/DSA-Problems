class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        set<pair<int,int>> st;

        dist[k] = 0;
        st.insert({0,k});

        while(!st.empty()){

            auto top = *st.begin();
            st.erase(st.begin());

            int time = top.first;
            int node = top.second;

            for(auto &edge: adj[node]){
                int neigh = edge.first;
                int weight = edge.second;

                if(dist[neigh] > time + weight){

                    if(dist[neigh] != INT_MAX)
                        st.erase({dist[neigh], neigh});

                    dist[neigh] = time + weight;
                    st.insert({dist[neigh], neigh});
                }
            }
        }

        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};