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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> level_nodes;
        int level_len, level = 0;
        vector< vector<int> >  ans;
        
        if(root != NULL)
            level_nodes.push(root);
        while(!level_nodes.empty())
        {
            level_len = level_nodes.size();
            ans.push_back(vector<int> ());
            
            while(level_len--)
            {
                TreeNode *node = level_nodes.front();
                ans[level].push_back(node->val);
                level_nodes.pop();
                
                if(node->left != NULL)  
                    level_nodes.push(node->left);
                if(node->right != NULL)  
                    level_nodes.push(node->right);
            }
            
            level++;
        }
        
        return ans;
    }
};
