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
    bool ArrayToBSTRange(TreeNode *root, int l, int r, const vector<int>& nums)
    {
        int mid = (l + r) / 2;
        
        if(l <= r)
        {
            root->val = nums[mid];
            root->left = new TreeNode();
            root->right = new TreeNode();
            
            if(!ArrayToBSTRange(root->left, l, mid - 1, nums))
                root->left = NULL;
            if(!ArrayToBSTRange(root->right, mid + 1, r, nums))
                root->right = NULL;
            
            return 1;
        }
        else
            return 0;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size())
            return NULL;
        
        TreeNode *new_root = new TreeNode();
        ArrayToBSTRange(new_root, 0, nums.size() - 1, nums);
        
        return new_root;
    }
};
