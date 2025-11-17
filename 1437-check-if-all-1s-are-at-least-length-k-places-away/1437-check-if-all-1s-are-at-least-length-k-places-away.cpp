class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int lastidx = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1 && lastidx != -1 && i - lastidx <= k){
                return false;
            }else if(nums[i] == 1){
                lastidx = i;
            }
        }
        return true;
    }
};