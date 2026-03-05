class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if(n <= 4){
            return 0;
        }
        sort(nums.begin(),nums.end());

        int min1 = nums[0];
        int min2 = nums[1];
        int min3 = nums[2];
        int min4 = nums[3];

        int max1 = nums[n-1];
        int max2 = nums[n-2];
        int max3 = nums[n-3];
        int max4 = nums[n-4];


        int ans = INT_MAX;

        ans = min(ans,max4-min1);
        ans = min(ans,max3-min2);
        ans = min(ans,max2-min3);
        ans = min(ans,max1-min4);

        return ans;
    }
};