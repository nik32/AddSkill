​
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
    TreeNode* buildTreeRec(const vector<int>& in, unordered_map<int, int>& inorder_indx, const vector<int>& pre, int *pre_indx, unordered_set<int>& vis)
    {
        int root = pre[++(*pre_indx)];
        TreeNode *node = new TreeNode(root);
        vis.insert(root);
        
        int in_indx = inorder_indx[root];
        
        if(in_indx && vis.find(in[in_indx - 1]) == vis.end())
            node->left = buildTreeRec(in, inorder_indx, pre, pre_indx, vis);
        
        if(in_indx < in.size()-1 && vis.find(in[in_indx + 1]) == vis.end())
            node->right = buildTreeRec(in, inorder_indx, pre, pre_indx, vis);
        
        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = inorder.size();
        if(!size)
            return NULL;
        
        unordered_map<int, int> inorder_indx;
        for(int i = 0 ; i < size ; i++)
            inorder_indx.insert({inorder[i], i});
        
        unordered_set<int> vis;
        int pre_indx = -1;
        TreeNode *root = buildTreeRec(inorder, inorder_indx, preorder, &pre_indx, vis);
        
        return root;
            
    }
};
