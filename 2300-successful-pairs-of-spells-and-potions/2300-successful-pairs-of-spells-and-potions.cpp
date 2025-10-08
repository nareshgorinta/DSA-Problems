class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            int left = 0;
            int right = potions.size()-1;
            int val = potions.size();
            while(left <= right){
                int mid = left + (right - left )/2;
                if((long long)potions[mid] * spells[i] >= success){
                    right = mid - 1;
                    val = mid;
                }else{
                    left = mid + 1;
                }
            }
            ans.push_back(potions.size() - val);
        }
        return ans;
    }
};