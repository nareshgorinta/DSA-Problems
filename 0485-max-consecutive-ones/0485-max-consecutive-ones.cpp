class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans  = 0;
        int cnt = 0;
        for(int i:nums){
            if(i==0){
                cnt =0;
                continue;
            }
            cnt++;
            ans = max(ans,cnt);
        }
        ans = max(ans,cnt);
        return ans;
    }
};