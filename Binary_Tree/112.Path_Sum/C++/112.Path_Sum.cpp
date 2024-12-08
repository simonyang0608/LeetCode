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
    bool hasPathSum(TreeNode * root, int targetSum) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        //   - int (target summary value)  //
        // Return type:                    //
        //   - bool (result flag)          //
        //=================================//
        if (! root) { return false; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record summary value /////
        int record_sum_val = (root->val);

        ///// Result flag /////
        bool res_flag = false;


        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, record_sum_val, targetSum, res_flag); //Recursion function call (i.e. whole root node)

        return res_flag;
    }


    void dfsTraversal(TreeNode * root, int & record_sum_val, int & targetSum, bool & res_flag)
    {
        //=====================================//
        // Input type:                         //
        //   - TreeNode * (root tree-node)     //
        //   - int ref. (record summary value) //
        //   - int ref. (target summary value) //
        //   - bool ref. (result flag)         //
        // Return type:                        //
        //   - void (no return)                //
        //=====================================//
        if ((! (root->left)) && (! (root->right))) //Issue, Boundary-case handling
        {
            ///// Check if the current summary value matched conditions or not /////
            if (record_sum_val == targetSum) { if (! res_flag) { res_flag |= true; } }
        }

        /*Whole process, flow*/
        if ((root->left))
        {
            record_sum_val += ((root->left)->val); //Update, Accumulate

            dfsTraversal((root->left), record_sum_val, targetSum, res_flag); //Recursion function call (i.e. root left-half node)
        }

        if ((root->right))
        {
            record_sum_val += ((root->right)->val); //Update, Accumulate

            dfsTraversal((root->right), record_sum_val, targetSum, res_flag); //Recursion function call (i.e. root right-half node)
        }

        record_sum_val -= (root->val); //Update, Reduce
    }
};
