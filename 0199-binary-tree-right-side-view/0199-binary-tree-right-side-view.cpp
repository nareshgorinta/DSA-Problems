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
    unordered_map<int,int> mp;
    int solve(TreeNode* root,int level){
        if(root){
            mp[level] = root->val;
            int left  = solve(root->left,level+1);
            int right = solve(root->right,level+1);
            return 1+max(left,right);
        }
        return 0;
    }
    vector<int> rightSideView(TreeNode* root) {
        int l = solve(root,0);
        vector<int> ans(l);
        for(int i=0;i<l;i++){
            ans[i] = mp[i];
        }
        return ans;
    }
};