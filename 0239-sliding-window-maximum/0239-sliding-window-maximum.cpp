class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>> dq;
        vector<int> ans;

        for(int i = 0; i < k; i++) {
            while(!dq.empty() && dq.back().first <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
        }
        ans.push_back(dq.front().first);

        for(int i = k; i < nums.size(); i++) {
            while(!dq.empty() && dq.back().first <= nums[i]) {
                dq.pop_back();
            }
            dq.push_back({nums[i], i});
            
            while(!dq.empty() && i - dq.front().second >= k) {
                dq.pop_front();
            }

            ans.push_back(dq.front().first);
        }

        return ans;
    }
};
