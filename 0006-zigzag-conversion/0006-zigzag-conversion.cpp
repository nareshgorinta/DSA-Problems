class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        string ans="";
        if(numRows == 1) return s;
        for(int i=0;i<numRows;i++){
            int val = 2*numRows - 2;
            for(int j=i;j<n;j+=val){
                ans+=s[j];
                if(i !=0 && i!= numRows -1){
                    int idx =  (numRows-i-1)*2 + j;
                    if(idx < n && idx >= 0){
                        ans+=s[idx];
                    }
                }
            }

        }
        return ans;
    }
};