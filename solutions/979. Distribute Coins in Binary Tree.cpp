/*
    The Sources from which you understood this question - 
        1. https://www.youtube.com/watch?v=rAztd-UzAjU (Explains - how to calculate the minimum number of moves for a node so that it has only 1 child)
        2. https://youtu.be/d4X9ovszrY4?t=750 (Explains - how to calculate the number of access coins the current node has. Watch this till 18:32 mins).
*/
​
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
    Logic of this question - 
    
    1. Firstly we need to notice is that the minimum number of moves required to balance the load will be sum of excess coins or the coin deficiet each node has.
    
    2. To find the excess coins each node has we just find the -
            excess coins its left child has (becuase the excess coins will always be transfered to the
            parent for it to distribute to other nodes) + the excess coins its right child has + coins 
            the node itself has - 1 (- 1 becuase the node will keep 1 coin for itself. So it is not access 
        
        Note - if we get excess coin as a negative value means that there is defecit in coins and thus those number of coins are required from its parent.
    
    3. Now the aboslute value of the excess coins at each node is the number of moves required to balance that node so that it has 1 coin (you can get that logically becuase if say it has 3 excess coins then it will take 3 moves to transfer the coins to its parent. Otherwise, if it has a defecit of 3 coins (i.e. -3 excess coins) then the parent will have to make 3 moves to transferr the nodes to thhis currr node for it to be balanced)
