class Solution {
public:
    string removeOuterParentheses(string s) {
        int left = 0;
        int right = 0;
        string ans;
        for(char c:s){
            if(c=='('){
                if(left == 0){
                    left++;
                }else{
                    ans+='(';
                    left++;
                }
            }else{
                right++;
                if(left == right){
                    left = 0;
                    right = 0;
                }else{
                    ans+=")";
                }
            }
        }
        return ans;
    }
};