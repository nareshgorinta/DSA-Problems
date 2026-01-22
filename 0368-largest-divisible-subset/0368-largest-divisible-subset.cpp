class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1) , parent(n,-1);
        int maxi = 0, lastindex =-1;
        for(int i=0;i<n;i++){
            for(int j =0;j<i;j++){
                if(nums[i] % nums[j] == 0){
                    if(dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if(maxi < dp[i]){
                maxi = dp[i];
                lastindex = i;
            }
        }
        vector<int> ans;
        while(lastindex != -1){
            ans.push_back(nums[lastindex]);
            lastindex = parent[lastindex];
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};