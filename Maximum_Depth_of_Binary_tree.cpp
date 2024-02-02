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
    //    LEVELWISE TRAVERSAL METHOD
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        queue<TreeNode*>Q;
        Q.push(root);
        int ct = 0;
        while(!Q.empty()){
            int n = Q.size();
            for(int i=0;i<n;i++){
                TreeNode* front = Q.front();
                if(front->right != NULL)Q.push(front->right);
                if(front->left != NULL)Q.push(front->left);
                Q.pop();
            }
            ct++;
        }
        return ct;
    }
};
