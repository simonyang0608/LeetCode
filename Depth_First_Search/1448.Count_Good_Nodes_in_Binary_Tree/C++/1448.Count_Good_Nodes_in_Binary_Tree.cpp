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
    int goodNodes(TreeNode * root) 
    {
        //==================================//
        // Input type:                      //
        //   - TreeNode * (root tree-node)  //
        // Return type:                     //
        //   - int (result summary counter) //
        //==================================//

        /*Initialize*/
        ///// Result summary counter /////
        int res_cnter = 0;

        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, (((-1) * 1e4) - 1), res_cnter); //Recursion function call (i.e. whole root tree-node)

        return res_cnter;
    }


    void dfsTraversal(TreeNode * root, int record_max_val, int & res_cnter)
    {
        //=======================================//
        // Input type:                           //
        //   - TreeNode * (root tree-node)       //
        //   - int (record maximun value)        //
        //   - int ref. (result summary counter) //
        // Return type:                          //
        //   - void (no return)                  //
        //=======================================//
        if (root == nullptr) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        ///// Check if the current root-value matched conditions or not /////
        if ((root->val) >= record_max_val)
        { 
            (res_cnter++); //Update, Accumulate

            dfsTraversal((root->left), (root->val), res_cnter); //Recursion function call (i.e. root left-half node)
            dfsTraversal((root->right), (root->val), res_cnter); //Recursion function call (i.e. root right-half node)
        }

        else
        {
            dfsTraversal((root->left), record_max_val, res_cnter); //Recursion function call (i.e. root left-half node)
            dfsTraversal((root->right), record_max_val, res_cnter); //Recursion function call (i.e. root right-half node)
        }
    }
};
