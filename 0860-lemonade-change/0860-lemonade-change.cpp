class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;

        for(int num:bills){
            if(num == 5){
                fives++;
            }else if(num == 10){
                tens++;
                if(fives != 0){
                    fives--;
                }else{
                    return false;
                }
            }else{
                if(tens != 0){
                    tens--;
                }else{
                    if(fives > 2){
                        fives-=2;
                    }else{
                        return false;
                    }
                }

                if(fives != 0){
                    fives --;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};