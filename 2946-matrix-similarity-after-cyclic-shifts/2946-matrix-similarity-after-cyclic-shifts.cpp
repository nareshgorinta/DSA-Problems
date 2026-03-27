class Solution {
public:
    void reverse(vector<int>& arr, int start, int end) {
        while (start < end) {
            swap(arr[start++], arr[end--]);
        }
    }

    void rotate(vector<int>& arr, int k, bool left) {
        int m = arr.size();
        k %= m; // Handle k > m
        if (k == 0) return;

        if (left) {
            // Left shift: Reverse [0, k-1], [k, m-1], then whole [0, m-1]
            reverse(arr, 0, k - 1);
            reverse(arr, k, m - 1);
            reverse(arr, 0, m - 1);
        } else {
            // Right shift: Reverse [0, m-k-1], [m-k, m-1], then whole [0, m-1]
            reverse(arr, 0, m - k - 1);
            reverse(arr, m - k, m - 1);
            reverse(arr, 0, m - 1);
        }
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat[0].size();
        
        // If k is a multiple of row length, no element actually changes position
        if (k % m == 0) return true;

        for (int i = 0; i < mat.size(); i++) {
            vector<int> original = mat[i];
            // Even rows (0-indexed) shift left, odd rows shift right
            rotate(mat[i], k, i % 2 == 0);
            
            if (mat[i] != original) return false;
        }
        
        return true;
    }
};
