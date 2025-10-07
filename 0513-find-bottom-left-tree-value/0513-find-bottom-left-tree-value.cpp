class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        int leftval = root->val;
        int maxLevel = 0;

        while(!q.empty()) {
            auto [node, level] = q.front();
            q.pop();

            // Update leftval if we are at a new level
            if(level > maxLevel) {
                leftval = node->val;
                maxLevel = level;
            }

            // Push left first, then right
            if(node->left) q.push({node->left, level+1});
            if(node->right) q.push({node->right, level+1});
        }

        return leftval;
    }
};
