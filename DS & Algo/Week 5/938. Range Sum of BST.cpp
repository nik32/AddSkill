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
private:
    int ans = 0;    
public:
    void DFS(TreeNode *root,const int l,const int r)
    {
        if(root == NULL)
            return;
        
        if(root->val >= l && root->val <= r)
            ans += root->val;
        
        DFS(root->left, l, r);
        DFS(root->right, l, r);
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        DFS(root, low, high);
        return ans;
    }
};
