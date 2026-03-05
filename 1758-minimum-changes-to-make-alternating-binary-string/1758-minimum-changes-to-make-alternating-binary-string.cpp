class Solution {
public:
    int minOperations(string s) {
        int ans = INT_MAX;
        int n = s.size();
        char zero = '0';
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(zero != s[i]){
                cnt++;
            }

            if(zero == '0'){
                zero = '1';
            }else{
                zero='0';
            }
        }
        ans = min(ans,cnt);
        zero = '1';
        cnt = 0;
        for(int i=0;i<n;i++){
            if(zero != s[i]){
                cnt++;
            }

            if(zero == '0'){
                zero = '1';
            }else{
                zero='0';
            }
        }
        ans = min(ans,cnt);
        return ans;
    }
};