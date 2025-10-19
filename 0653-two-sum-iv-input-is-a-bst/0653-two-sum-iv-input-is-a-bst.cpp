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
    bool solve(TreeNode* root,int k,unordered_set<int> set){
        if(!root){
            return false;
        }
        if(set.find(root->val) !=set.end()){
            return true;
        }else{
            set.insert(k - root->val);
        }
        return solve(root->left,k,set) || solve(root->right,k,set);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;

        return solve(root,k,set);
    }
};