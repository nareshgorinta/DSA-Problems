class Solution {
public:
    bool solve(string s1,string s2){
        if(s1.length() != s2.length()){
            return false;
        }
        if(s1 == "" && s2 == ""){
            return true;
        }

        if(s1.compare(s2) == 0){
            return true;
        }

        int n = s1.size();

        for(int i=1;i<n;i++){
            bool swap = solve(s1.substr(0,i),s2.substr(n-i,i)) && solve(s1.substr(i,n-i),s2.substr(0,n-i));
            bool not_swap = solve(s1.substr(0,i),s2.substr(0,i)) && solve(s1.substr(i,n-i),s2.substr(i,n-i));

            if(swap || not_swap){
                return true;
            }
        }
        return false;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};