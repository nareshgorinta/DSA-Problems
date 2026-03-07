#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int cur = 0;

        for(int i = 2; i < n; i++){
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
                cur = cur + 1;
                ans+=cur;
            }else{
                cur = 0;
            }
        }

        return ans;
    }
};