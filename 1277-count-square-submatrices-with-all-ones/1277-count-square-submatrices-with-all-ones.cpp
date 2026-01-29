class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int sum = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    matrix[i][j] = 1 + std::min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]});
                }
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};
