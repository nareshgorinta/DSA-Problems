class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>,int>> q;

        int r = mat.size();
        int c = mat[0].size();

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j] == 0){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            int k = q.size();
            for(int d=0;d<k;d++){
                auto val = q.front();
                int i = val.first.first;
                int j = val.first.second;
                int a = val.second;
                q.pop();
                vector<int>dx = {-1,0,1,0};
                vector<int>dy = {0,-1,0,1};


                for(int p=0;p<4;p++){
                    int X = i + dx[p];
                    int Y = j + dy[p];

                    if( X>=0 && Y>=0 && X<r && Y<c){
                        if(mat[X][Y] == 1){
                            q.push({{X,Y},a+1});
                            mat[X][Y] = - (a+1);
                        }
                    }
                }
            }

        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mat[i][j]= abs(mat[i][j]);
            }
        }
        return mat;
        
    }
};