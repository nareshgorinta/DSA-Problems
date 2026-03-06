class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.size();
        int flag  =0;
        for(int i=1;i<n;i++){
            if(s[i] == '1' && flag){
                return false;
            }
            if(s[i] == '0'){
                flag = 1;
            }

        }
        return true;
    }
};