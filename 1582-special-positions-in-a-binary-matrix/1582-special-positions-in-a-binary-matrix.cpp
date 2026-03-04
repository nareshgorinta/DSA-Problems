class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int cnt = 0;

        for(int i=0;i<n;i++){
            int idx = -1;

            for(int j=0;j<m;j++){
                if(mat[i][j] == 1){
                    if(idx == -1) idx = j;
                    else{
                        idx = -1;
                        break;
                    }
                }
            }

            if(idx != -1){
                bool ok = true;

                for(int k=0;k<n;k++){
                    if(k != i && mat[k][idx] == 1){
                        ok = false;
                        break;
                    }
                }

                if(ok) cnt++;
            }
        }

        return cnt;
    }
};