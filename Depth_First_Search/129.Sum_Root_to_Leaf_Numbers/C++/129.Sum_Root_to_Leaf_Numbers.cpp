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
    int sumNumbers(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - int (result summary value)  //
        //=================================//

        /*Initialize*/
        ///// Result summary value /////
        int res_sum_val = 0;

        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, (root->val), res_sum_val); //Recursion function call (i.e. whole root tree-node)

        return res_sum_val;
    }


    void dfsTraversal(TreeNode * root, int record_sum, int & res_sum_val)
    {
        //=====================================//
        // Input type:                         //
        //   - TreeNode * (root tree-node)     //
        //   - int (record summary value)      //
        //   - int ref. (result summary value) //
        // Return type:                        //
        //   - void (no return)                //
        //=====================================//
        if (((root->left) == nullptr) && ((root->right) == nullptr)) //Issue, Boundary-case handling
        {
            res_sum_val += record_sum; //Update, Accumulate

            return;
        }

        /*Whole process, flow*/
        if ((root->left))
        {
            dfsTraversal((root->left), ((10 * record_sum) + ((root->left)->val)), res_sum_val); //Recursion function call (i.e. root left-half node)
        }

        if ((root->right))
        {
            dfsTraversal((root->right), ((10 * record_sum) + ((root->right)->val)), res_sum_val); //Recursion function call (i.e. root right-half node)
        }
    }
};
