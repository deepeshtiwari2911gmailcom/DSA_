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
    //Modified Maxdepth gives maximum depth of tree when tree is balaced ;
    int modifiedmaxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lefth = modifiedmaxDepth(root->left);
        if(lefth == -1)return -1;

        int righth = modifiedmaxDepth(root->right);
        if(righth == -1)return -1;
        
        if(abs(lefth - righth) > 1)return -1;
        return 1+max(lefth,righth);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        // calculate for root node 
        int fl = modifiedmaxDepth(root);
        if(fl==-1)return false;
        return true;

    }
};
