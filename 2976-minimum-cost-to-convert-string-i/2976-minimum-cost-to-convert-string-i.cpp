class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        unordered_map<char,int> mp;
        int idx = 0;
        const long long INF = 1e15;

        // 1️⃣ Mapping
        for (char ch : original)
            if (mp.find(ch) == mp.end())
                mp[ch] = idx++;

        for (char ch : changed)
            if (mp.find(ch) == mp.end())
                mp[ch] = idx++;

        int V = idx;

        // 2️⃣ Distance matrix
        vector<vector<long long>> dist(V, vector<long long>(V, INF));
        for (int i = 0; i < V; i++)
            dist[i][i] = 0;

        // 3️⃣ Build graph
        for (int i = 0; i < original.size(); i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // 4️⃣ Floyd–Warshall
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j],
                                          dist[i][k] + dist[k][j]);

        // 5️⃣ Compute answer
        long long totalCost = 0;
        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;

            if (mp.find(source[i]) == mp.end() ||
                mp.find(target[i]) == mp.end())
                return -1;

            int u = mp[source[i]];
            int v = mp[target[i]];

            if (dist[u][v] == INF) return -1;

            totalCost += dist[u][v];
        }

        return totalCost;
    }
};
