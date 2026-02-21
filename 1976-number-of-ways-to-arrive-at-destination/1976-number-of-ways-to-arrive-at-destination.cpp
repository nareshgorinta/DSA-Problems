class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        vector<pair<long long,int>> dist(n, {LLONG_MAX, 0});

        set<pair<long long,int>> st;

        dist[0] = {0, 1};
        st.insert({0, 0});

        while(!st.empty()){
            auto it = *st.begin();
            st.erase(st.begin());

            int node = it.second;
            long long dis = it.first;

            if(dis > dist[node].first) continue;
            for(auto a : adj[node]){
                int neigh = a.first;
                long long weight = a.second;

                if(dist[neigh].first >= dis + weight){
                    if(dist[neigh].first == dis + weight){
                        dist[neigh].second+=dist[node].second;
                    }else{
                        dist[neigh].first = dis + weight;
                        dist[neigh].second = dist[node].second;
                        st.insert({dist[neigh].first, neigh});
                    }
                }
            }
        }
        return dist[n-1].second;
    }
};