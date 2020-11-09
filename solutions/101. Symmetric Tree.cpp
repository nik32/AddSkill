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
    bool solution(const vector< vector<int> >& arr)
    {
        for(int i = 0 ; i < arr.size(); i++)
        {
            int e = arr[i].size() - 1, s = 0;
            while(s < e)
                if(arr[i][s++] != arr[i][e--])
                    return 0;
        }
        
        return 1;
    }
    
    void levelOrderHelper(TreeNode* root, vector< vector<int> > &level_order, int level)
    {
        if(root==NULL)
        {
            level_order[level].push_back(-1);
            return;
        }
        
