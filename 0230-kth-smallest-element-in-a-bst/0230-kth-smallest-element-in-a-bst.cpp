#include <iostream>
using namespace std;

// Node Structure
class Solution {
public:
// Recursive function for inorder traversal of the tree and 
// find its kth smallest value
int kthSmallestRecur(TreeNode* root, int &cnt, int k) {
    if (root == nullptr) return -1;
    
    int left = kthSmallestRecur(root->left, cnt, k);
    
    // If kth smallest is found in left 
    // subtree, then return it
    if (left != -1) return left;
    
    cnt++;
    
    // If curr node is kth smallest,
    // return it
    if (cnt == k) return root->val;
    
    // Else process the right subtree
    // and return its value
    int right = kthSmallestRecur(root->right, cnt, k);
    return right;
}

// Function to find kth Smallest
int kthSmallest(TreeNode* root, int k) {
    int cnt = 0;
    return kthSmallestRecur(root, cnt, k);
}
};