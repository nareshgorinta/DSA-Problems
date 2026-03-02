/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int count = 0;
    
    void dfs(TreeNode* root, long long currSum, int targetSum) {
        if (!root) return;
        
        currSum += root->val;
        
        if (currSum == targetSum)
            count++;
        
        dfs(root->left, currSum, targetSum);
        dfs(root->right, currSum, targetSum);
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        
        dfs(root, 0, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        
        return count;
    }
};