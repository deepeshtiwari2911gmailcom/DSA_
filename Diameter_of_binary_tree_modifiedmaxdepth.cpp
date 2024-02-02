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
    // maxdepth is being modified a varible d is passed by refrence
    // so it stores the max value of d if occurs at any node
    // nice approch 
    int modifiedmaxDepth(TreeNode* root, int& d) {
        if(root == NULL) return 0;
        
        int lefth = modifiedmaxDepth(root->left,d);
        int righth = modifiedmaxDepth(root->right,d);
        
        d = max(d, lefth + righth);
        return 1+max(lefth,righth);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;

        int d = 0;
        modifiedmaxDepth(root,d);
        return d;
        
        
    }
};
