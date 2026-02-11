class Solution {
public:
    bool ischeck(vector<int>freq){
        int val = 0;
        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue;
            if(val == 0){
                val = freq[i];
            }else if(val != freq[i]){
                return false;
        }
        }
        return true;
    }
    int longestBalanced(string s) {
        int n = s.size();
        int maxi =1;
        
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(ischeck(freq)){
                    maxi = max(maxi,j-i+1);
                }
            }

        }
        return maxi;
    }
};