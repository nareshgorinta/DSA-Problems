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
    int left(TreeNode* root){
        int cnt = 0;
        TreeNode* lf = root;
        while(lf){
            cnt++;
            lf = lf->left;
        }
        return cnt;
    }
    int right(TreeNode* root){
        int cnt = 0;
        TreeNode* rf = root;
        while(rf){
            cnt++;
            rf = rf->right;
        }
        return cnt;
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }

        int l = left(root);
        int r = right(root);

        if(l == r){
            return (1 << l) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};