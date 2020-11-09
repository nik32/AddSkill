/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool Treverse(TreeNode* root, long l, long r)
    {
        if(root == NULL)
            return 1;
        if(root->val < l || root->val > r)
            return 0;
        else
        {
            bool left, right;
            left = Treverse(root->left, l, r);
            right = Treverse(root->right, l, r);
            if(left != 1 || right != 1)
                return 0;
            else
                return 1;
        }
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return 1;
        
        bool l = 1, r = 1;
        if(root->left != NULL)
            l = Treverse(root->left, INT_MIN, (long) root->val - 1);
        if(root->right != NULL)
            r = Treverse(root->right, (long) root->val + 1, INT_MAX);
        
        if(l != 1 || r != 1)
            return 0;
        
        l = 1, r = 1;
        if(root->left != NULL)
            l = isValidBST(root->left);
        if(root->right != NULL)
            r = isValidBST(root->right);
            
        if(l != 1 || r!= 1)
            return 0;
        
        return 1;
    }
};
