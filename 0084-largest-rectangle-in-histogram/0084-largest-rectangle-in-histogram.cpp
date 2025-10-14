class Solution {
public:
    vector<int> left(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n,-1);

        stack<int> st;

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> right(vector<int> arr){
        int n = arr.size();
        vector<int> ans(n,n);

        stack<int> st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = n;
            }else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> NSL = left(heights);
        vector<int> NSR = right(heights);
        int Max = 0;
        for(int i=0;i<n;i++){
            int width = NSR[i] - NSL[i] - 1;
            Max = max(Max,width*heights[i]);
        }
        return Max;
    }
};