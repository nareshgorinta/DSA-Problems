class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> rat(n,1);

        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){
                rat[i] = rat[i-1] + 1;
            }
        }

        for(int i=n-2;i>=0;i--){
            if(ratings[i] > ratings[i+1]){
                rat[i] = max(rat[i],rat[i+1] + 1);
            }
        }
        int ans = std::accumulate(rat.begin(),rat.end(),0);
        return ans;
    }
};