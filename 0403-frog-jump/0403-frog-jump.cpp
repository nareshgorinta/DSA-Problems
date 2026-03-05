class Solution {
public:
    bool solve(int i,int move,vector<int>& stones,vector<vector<int>>&dp,unordered_map<int,int>&mp){
        int n = stones.size();
        if(i == n-1){
            return true;
        }

        if(i >= n){
            return false;
        }

        if(dp[i][move] != -1){
            return dp[i][move];
        }
        bool a=false,b=false,c=false;

        if(mp.find(stones[i] + move-1) != mp.end() && move > 1){
            int idx = mp[stones[i] + move-1];
            a = solve(idx,move-1,stones,dp,mp);
        }

        if(mp.find(stones[i] + move) != mp.end()){
            int idx = mp[stones[i] + move];
            b = solve(idx,move,stones,dp,mp);
        }

        if(mp.find(stones[i] + move+1) != mp.end()){
            int idx = mp[stones[i] + move+1];
            c = solve(idx,move+1,stones,dp,mp);
        }

        dp[i][move] = a || b || c;
        return dp[i][move];
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size();

        vector<vector<int>> dp(n,vector<int>(n,-1));

        unordered_map<int,int> mp;

        for(int i=0;i<stones.size();i++){
            mp[stones[i]] = i;
        }

        if(mp.find(1) != mp.end()){
            return solve(1,1,stones,dp,mp);
        }
        return false;
    }
};