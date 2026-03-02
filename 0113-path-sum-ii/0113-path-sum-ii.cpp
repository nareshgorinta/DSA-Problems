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
    vector<vector<int>> ans;
    void solve(TreeNode* root,int targetSum,vector<int> &arr){
        if(!root){
            return ;
        }

        if(root && !root->left && !root->right && root->val == targetSum){
            arr.push_back(root->val);
            ans.push_back(arr);
            arr.pop_back();
            return ;
        }
        arr.push_back(root->val);

        solve(root->left,targetSum - root->val,arr);
        solve(root->right,targetSum-root->val,arr);

        arr.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>arr;
        solve(root,targetSum,arr);
        return ans;
    }
};