class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;

        vector<long long> maxSum(n, 0);
        vector<long long> minSum(n, 0); 

        vector<int> prevGreater(n), nextGreater(n);

        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long count = (long long)(i - prevGreater[i]) * (nextGreater[i] - i);
            maxSum[i] = nums[i] * count;
            result += maxSum[i];
        }

        vector<int> prevSmaller(n), nextSmaller(n);

        while (!st.empty()) st.pop();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            long long count = (long long)(i - prevSmaller[i]) * (nextSmaller[i] - i);
            minSum[i] = nums[i] * count;
            result -= minSum[i];
        }

        return result;
    }
};