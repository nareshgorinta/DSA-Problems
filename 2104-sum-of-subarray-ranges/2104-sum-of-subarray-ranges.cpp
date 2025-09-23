class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int l = nums.size();
        int count = 0;
        for(int i=0;i<l;i++){
            int Min = nums[i];
            int Max = nums[i];
            for(int j=i;j<l;j++){
                Min = min(Min,nums[j]);
                Max = max(Max,nums[j]);
                count += Max - Min;
            }
        }
        return count;
    }
};