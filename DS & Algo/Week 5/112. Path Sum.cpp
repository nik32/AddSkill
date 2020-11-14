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
private :
    bool ans = 0; 
    
public:
    void DFS(TreeNode* root, const int sum, int path_sum)
    {
        if(root == NULL)
            return;
        
        path_sum += root->val;
        if(path_sum == sum && root->left == NULL && root->right == NULL)
            ans = 1;
        
        if(!ans)
            DFS(root->left, sum, path_sum);
        if(!ans)
            DFS(root->right, sum, path_sum);
        
    }
    bool hasPathSum(TreeNode* root, int sum) {
        DFS(root, sum, 0);
        return ans;
    }
};
