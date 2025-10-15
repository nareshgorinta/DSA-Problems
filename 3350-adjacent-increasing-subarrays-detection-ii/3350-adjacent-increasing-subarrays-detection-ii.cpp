class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int cur = 1;
        int prev =0;
        int ans= 0 ;
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]){
                cur++;
            }else{
                prev = cur;
                cur = 1;
            }
            ans = max(ans,max(cur/2,min(prev,cur)));

        }
        return ans;
    }
};