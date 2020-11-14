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
int ans = 0;
public:
    void DFS(TreeNode* root,int level)
    {
        if(root == NULL)
        {
            ans = level > ans ? level : ans;
            return ;
        }
        
        DFS(root->left, level+1);
        DFS(root->right, level+1);
    }
    
    int maxDepth(TreeNode* root) {
        DFS(root, 0);
        return ans;
    }
};
