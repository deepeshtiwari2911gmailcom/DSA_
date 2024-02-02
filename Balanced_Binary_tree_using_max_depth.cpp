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
    // Maxdepth gives maximum depth of tree;
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lefth = maxDepth(root->left);
        int righth = maxDepth(root->right);

        return 1+max(lefth,righth);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        // calculate for root node 
        int lefth = maxDepth(root->left);
        int righth = maxDepth(root->right);

        if(abs(lefth-righth)>1)return false;

        // Apply recursion to test for child nodes
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left or !right)return false;
        return true;
    }
};
