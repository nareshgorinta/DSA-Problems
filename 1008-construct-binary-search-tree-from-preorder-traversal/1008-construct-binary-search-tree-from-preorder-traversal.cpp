class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.empty()) return nullptr; // safety check

        stack<TreeNode*> st;
        TreeNode* root = new TreeNode(preorder[0]);
        st.push(root);

        // start from i = 1, since preorder[0] is already root
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode* node = new TreeNode(preorder[i]);

            if (preorder[i] < st.top()->val) {
                // new node is the left child of the stack top
                st.top()->left = node;
            } else {
                TreeNode* parent = nullptr;
                // find the parent for which this node is the right child
                while (!st.empty() && preorder[i] > st.top()->val) {
                    parent = st.top();
                    st.pop();
                }
                parent->right = node;
            }

            st.push(node);
        }

        return root;
    }
};
