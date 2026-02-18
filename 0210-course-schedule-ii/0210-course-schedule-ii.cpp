class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topo;

        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses,vector<int>(numCourses,0));

        queue<int> q;

        for(auto it:prerequisites){
            int u = it[0];
            int v = it[1];

            adj[u][v] = 1;
            indegree[v]++;
        }

        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int v=0;v<numCourses;v++){
                if(adj[node][v] == 1){
                    indegree[v]--;


                    if(indegree[v] == 0){
                        q.push(v);
                    }
                }
            }
        }

        reverse(topo.begin(),topo.end());
        if(topo.size() == numCourses){
            return topo;
        }
        return {};
    }
};