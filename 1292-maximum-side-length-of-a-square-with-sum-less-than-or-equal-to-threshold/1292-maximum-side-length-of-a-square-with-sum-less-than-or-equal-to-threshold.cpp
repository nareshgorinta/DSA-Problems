class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        // prefix sum array (n+1) x (m+1)
        vector<vector<long long>> p(n + 1, vector<long long>(m + 1, 0));

        // build prefix sum
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                p[i][j] = mat[i - 1][j - 1]
                        + p[i - 1][j]
                        + p[i][j - 1]
                        - p[i - 1][j - 1];
            }
        }

        // function to check if any k×k square has sum <= threshold
        auto possible = [&](int k) {
            for (int i = 0; i + k <= n; i++) {
                for (int j = 0; j + k <= m; j++) {
                    long long sum = p[i + k][j + k]
                                  - p[i][j + k]
                                  - p[i + k][j]
                                  + p[i][j];

                    if (sum <= threshold) return true;
                }
            }
            return false;
        };

        int low = 0, high = min(n, m);
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(mid)) {
                ans = mid;
                low = mid + 1;   // try bigger square
            } else {
                high = mid - 1;  // reduce square size
            }
        }

        return ans;
    }
};
