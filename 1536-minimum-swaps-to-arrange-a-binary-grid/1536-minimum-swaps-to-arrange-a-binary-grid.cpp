class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>arr(n,0);

        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j] != 0){
                    arr[i] = sum;
                    break;
                }else{
                    sum+=1;
                }
                arr[i] = sum;
            }
        }
        for(int a:arr){
            cout << a << ' ';
        }

        int steps  = 0;

        for(int i=0;i<n;i++){
            int val = n-i-1;
            int j;
            bool found = false;
            for(j=i;j<n;j++){
                if(val <= arr[j]){
                    found = true;
                    break;
                }
            }
            if (found) {
                steps += (j - i); // Add the number of adjacent swaps needed
                
                // Physically move the row at index 'j' to index 'i' 
                // by shifting all elements between them one step down
                int temp = arr[j];
                for (int k = j; k > i; k--) {
                    arr[k] = arr[k - 1];
                }
                arr[i] = temp; // Place the selected row at its new position
            }else{
                return -1;
            }
        }

        return steps;
    }
};