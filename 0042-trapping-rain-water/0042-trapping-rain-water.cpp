class Solution {
public:
    int trap(vector<int>& height) {
        int l = height.size();

        int left_max = 0;
        int right_max = 0;

        int left = 0;
        int right = l-1;
        int water = 0;
        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] < left_max){
                    water += left_max - height[left];
                }else{
                    left_max = height[left];
                }
                left++;
            }
            else{
                if(height[right] < right_max){
                    water += right_max - height[right];
                }else{
                    right_max = height[right];
                }
                right--;
            }
        }
        return water;

    }
};