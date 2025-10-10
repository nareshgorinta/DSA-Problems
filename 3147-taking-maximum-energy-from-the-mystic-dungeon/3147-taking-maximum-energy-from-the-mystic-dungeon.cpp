class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n  =  energy.size()-1;
        for(int i=n-k;i>=0;i--){
            energy[i] += energy[i+k];
        }
        int Max = INT_MIN;
        for(int i=0;i<=n;i++){
            Max = max(energy[i],Max);
        }
        return Max;
    }
};