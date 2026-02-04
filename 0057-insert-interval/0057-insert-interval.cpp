class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();

        // Step 1: add all non-overlapping before newInterval
        while(i < n && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        // Step 2: merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        ans.push_back(newInterval); // insert merged interval

        // Step 3: add remaining intervals
        while(i < n) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};
