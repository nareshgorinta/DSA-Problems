class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int val = neededTime[0];
        for(int i=1;i<colors.size();i++){
            if(colors[i] == colors[i-1]){
                if(val <= neededTime[i]){
                    time += val;
                    val  = neededTime[i];
                }else{
                    time +=neededTime[i];
                }
            }else{
                val = neededTime[i];
            }
        }
        return time;
    }
};