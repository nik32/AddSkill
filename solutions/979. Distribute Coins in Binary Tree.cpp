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
    int moves = 0;
public:
    int numOfExcessCoins(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        
        int excess_l = numOfExcessCoins(root->left);
        int excess_r = numOfExcessCoins(root->right);
        
        int excess_curr = root->val + excess_l + excess_r - 1;
        
        moves += abs(excess_curr);
        
        return excess_curr;
    }
    
    int distributeCoins(TreeNode* root) {            
        numOfExcessCoins(root);
        return moves; 
    }
};
