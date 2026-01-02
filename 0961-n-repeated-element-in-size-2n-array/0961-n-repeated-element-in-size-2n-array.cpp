class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int l=nums.size();

        unordered_map<int,int> freq;

        for(int n:nums){
            freq[n]++;
        }

        for(auto val:freq){
            if(val.second == l/2){
                return val.first;
            }
        }
        return 0;
    }
};