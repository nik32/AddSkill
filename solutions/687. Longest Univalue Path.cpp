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
​
/*
    Terms to understand the comments -
    1. "single" univariate path - this is a univariate path which is not a combination of univariate path starting from left subtree and ending at right subtree. So path given in Ex 1 is single univariate path and path given in Ex 2 is not a single univariate path
    
    Approach - 
    1. Apprach is simple for each node I find the longest "single univariate paths" coming from the left & right subtree. 
    2. Now if our current node is eqal to left child that mean it will be part of our univarite path from left and similarly if our current node is eqal to right child that mean it will be part of our univarite path from right. 
    3. As our current node can be part of a non single univariate path (which starts from right and ends in left subtree node), we add the both paths from left and right and see if it is max and make cahnges to ans accordinly.
    4. But while reutrning we have to return the longest "single" univariate path so we return the max of single univariate paht from left & single univariate parth fomr right.
*/
​
class Solution {
private:
    int ans = 0;
public:
    int pathHelper(TreeNode *root)//this function returns the length of longest "single univariate path" from root
    {
        if(root == NULL)
            return 0;
        
        int l = pathHelper(root->left);//We get the longest single univariate path in left subtree
        int r = pathHelper(root->right);//We get the longest single univariate path in right subtree
        
        if(root->left != NULL)
            l = root->left->val == root->val ? l + 1 : 0;//if the value of the current node matches with left node that means we can include edge between these nodes in our longest single univariate path from left side. If not then there is no univariate path on the left so we store 0 in l
        if(root->right != NULL)
            r = root->right->val == root->val ? r + 1 : 0;//if the value of the current node matches with right node that means we can include the edge between these nodes in our longest single univariate path from right side.If not then there is no univariate path on the right so we store 0 in r
        
        ans = (l + r > ans) ? l + r : ans;//Now becuase the ans can be a combination of single univaraite paths from left and right we add them and see if it is max and update ans accordingly 
        return max(l, r);//But actually this function only returns the longest "single univariate path" so we have to see which amonsgt left and right paths is longest and return that. This is to deal with case like this [1,null,1,1,1,1,1,1] whereas if we return l+r then the logic won't work. 
    }
    int longestUnivaluePath(TreeNode* root) {
        pathHelper(root);
        return ans;
    }
};
