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
    bool ans = 1;
public:
    void DFS(TreeNode *t1, TreeNode *t2)
    {
        if(t1 == NULL && t2 == NULL)
            return;
        
        if((t1 == NULL && t2 != NULL) || (t2 == NULL && t1 != NULL) || t1->val != t2->val)
            ans = 0;
        
        if(ans)
            DFS(t1->left, t2->left);
        if(ans)
            DFS(t1->right, t2->right);
        
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        DFS(p, q);
        return ans;
    }
};
