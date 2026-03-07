#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return 0;

        int cnt = 0;
        int left = 0;
        int size = nums[1] - nums[0];

        for(int right = 2; right < n; right++){

            if(nums[right] - nums[right - 1] != size){
                left = right - 1;
                size = nums[right] - nums[right - 1];
            }

            if(right - left + 1 >= 3){
                cnt += (right - left - 1);
            }
        }

        return cnt;
    }
};