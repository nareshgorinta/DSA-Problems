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
    int sum =0;
    int solve(TreeNode* root,int val){
        if(!root){
            return 0;
        }
        val = (val * 2) + root->val;

        if(!root->right && !root->left){
            sum+=val;
            return 0;
        }
        solve(root->left,val);
        solve(root->right,val);

        return 0;
    }
    int sumRootToLeaf(TreeNode* root) {
        solve(root,0);
        return sum;
    }
};