class Solution {
public:
    int longestValidParentheses(string s) {
        string  s1 = ')' + s;
        int ans  = 0;
        int n = s1.size();
        vector<int>dp(n,0);
        for(int i=1;i<s1.size();i++){
            if(s1[i] == '('){
                dp[i] = 0;
            }else{
                if(s1[i-1] == '('){
                    dp[i] = dp[i-2] + 2;
                }else{
                    int j = i - dp[i-1] - 1;
                    if(j>0 && s1[j] == '('){
                        dp[i] = dp[i-1] + 2 + dp[j-1];
                    }
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};