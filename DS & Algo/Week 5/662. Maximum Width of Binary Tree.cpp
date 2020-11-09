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
/*The approach is simple - 
    1) I do BFS using treverseLevel()
    2) level_nodes[] stores the nodes at each level just the twist is - it also store the index of a perticular node using heap indexing formulas {left of i = 2*i, right of i = 2*i+1}
    3) now if we know the index of each node then we can just do a subtraction of rightmost node's index (Stored in r) and leftmost node's index (stored in l), at each level, to get the number of nodes at each level.
    4) and the level having maximum num of node will be our ans*/
​
class Solution {
private :
    int ans = 1;
    struct data{
        TreeNode *node;
        double indx; //index can become way too long so double
    };
    
public:    
    void treverseLevel(const vector<data>& level_nodes)
    {
        int num_of_nodes = level_nodes.size();
        if(!num_of_nodes)
            return; 
        
        double l = level_nodes[0].indx, r = level_nodes[num_of_nodes - 1].indx;        
        ans = r - l + 1 > ans ? (int) (r - l + 1) : ans;
        
        //we need to treverse through all the nodes at a level coz its not necessary that the leftmost node at a level will have both left and right child. In which case we have to find the first node which has a child and this nodes child will become our leftmost node at next level.
        vector<data> next_level_nodes;
        for(int i = 0 ; i < num_of_nodes ; i++)  
        {
            if(level_nodes[i].node->left != NULL)
                next_level_nodes.push_back({level_nodes[i].node->left, (num_of_nodes == 1 ? 1 : level_nodes[i].indx) * 2}); /*the ternary operator is used to save from oveflow*/
            
