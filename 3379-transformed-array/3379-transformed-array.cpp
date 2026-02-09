class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);

        

        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                int val = nums[i];
                int rem = val%n;
                result[i] = nums[(i+rem)%n];
            }else{
                int val = nums[i];
                int rem = abs(val) % n;
                result[i] = nums[(i - rem + n) % n];
            }
        }
        return result;
        
    }
};