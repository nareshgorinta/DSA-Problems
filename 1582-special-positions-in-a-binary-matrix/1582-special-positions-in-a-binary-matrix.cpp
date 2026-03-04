class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n  = mat.size();
        int m  = mat[0].size();

        vector<int>vert(m,0);
        vector<int>horz(n,0);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    vert[j]+=1;
                    horz[i]+=1;
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]  && vert[j] == 1 && horz[i] == 1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};