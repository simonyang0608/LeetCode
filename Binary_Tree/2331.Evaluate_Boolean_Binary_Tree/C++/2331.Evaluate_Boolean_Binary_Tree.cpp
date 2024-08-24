/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfsTraversal(TreeNode * root)
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - bool (result flag)          //
        //=================================//
        if ((! (root->left)) && (! (root->right))) //Issue, Boundary-case handling
        {
            return (root->val);
        }

        /*Whole process, flow*/
        ///// Step 1: Recursion-based DFS loop traversal /////
        bool root_left = dfsTraversal((root->left)); //Recursion function call (i.e. root left-half node)
        bool root_right = dfsTraversal((root->right)); //Recursion function call (i.e. root right-half node)

        ///// Step 2: Check if the current bit-wise operations is or or and /////
        if ((root->val) == 2) //OR operations
        {
            return (root_left | root_right);
        }

        return (root_left & root_right); //AND operations
    }


    bool evaluateTree(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - bool (result flag)          //
        //=================================//

        /*Recursion-based DFS loop traversal*/
        return dfsTraversal(root); //Recursion function call (i.e. whole node)
    }
};
