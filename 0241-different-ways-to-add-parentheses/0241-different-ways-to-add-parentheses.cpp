class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> diffWaysToCompute(string expression) {
        // If already computed, return cached result
        if (memo.count(expression)) return memo[expression];

        vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                // Split into left and right parts
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                // Combine all results
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') res.push_back(l + r);
                        else if (c == '-') res.push_back(l - r);
                        else res.push_back(l * r);
                    }
                }
            }
        }
        // If res is empty, the expression is a number
        if (res.empty()) res.push_back(stoi(expression));
        // Cache and return
        memo[expression] = res;
        return res;
    }
};