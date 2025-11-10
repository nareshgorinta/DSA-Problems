
    
class Solution {
public:
    int minOperations(vector<int>& nums) {

        stack<int> st;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){

            if(nums[i] == 0){
                ans += st.size();
                while(!st.empty()) {
                    st.pop();
                }
                continue;
            }

            while(!st.empty() && st.top() > nums[i]){
                st.pop();
                ans++;
            }

            if(st.empty() || (st.top() != nums[i] && nums[i] != 0)){
                st.push(nums[i]);
            }

        }

        ans += st.size();
        return ans;
    }
};