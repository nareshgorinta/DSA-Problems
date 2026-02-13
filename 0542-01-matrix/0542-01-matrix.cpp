class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();
        int INF = 1e9;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j] != 0){
                    int top = ( i > 0) ? mat[i-1][j] : INF;
                    int left = (j > 0) ? mat[i][j-1] : INF;

                    mat[i][j] = 1 + min(top,left);
                }
            }
        }

        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(mat[i][j] != 0){
                    int bottom = (i < r-1) ? mat[i+1][j] : INF;
                    int right = (j< c-1) ? mat[i][j+1] : INF;

                    mat[i][j] = min(mat[i][j],1+min(bottom,right));
                }
            }
        }
        return mat;

    }
};