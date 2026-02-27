class Solution {
public:
    vector<vector<int>> ans;
    void back(int i,int n,int k,vector<int>&arr){
        if(arr.size() == k){
            ans.push_back(arr);
            return ;
        }

        for(int j=i;j<=n;j++){
            arr.push_back(j);
            back(j+1,n,k,arr);
            arr.pop_back();
        }
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        back(1,n,k,arr);
        return ans;

    }
};