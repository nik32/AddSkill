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
    vector<int> merge(const vector<int>& a1, const vector<int>& a2)
    {
        vector<int> ans;
        int i1 = 0, i2 = 0, size1 = a1.size(), size2 = a2.size();
        while(i1 < size1 && i2 < size2)
        {
            if(a1[i1] <= a2[i2])
                ans.push_back(a1[i1++]);
            else
                ans.push_back(a2[i2++]);
        }
        
        while(i1 < size1)
            ans.push_back(a1[i1++]);
        
        while(i2 < size2)
            ans.push_back(a2[i2++]);
        
        return ans;
    }
    
    void inOrder(TreeNode* root, vector<int>& ans)
