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
    int sumEvenGrandparent(TreeNode * root) 
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
        dfsTraversal(root, res_sum_val); //Recursion function call (i.e. whole root-node)

        return res_sum_val;
    }


    void dfsTraversal(TreeNode * root, int & res_sum_val)
    {
        //=====================================//
        // Input type:                         //
        //   - TreeNode * (root tree-node)     //
        // Return type:                        //
        //   - int ref. (result summary value) //
        //=====================================//

        /*Whole process, flow*/
        ///// Check if the child-nodes existed or not /////
        if ((root->left) != nullptr)
        {
            ///// Check if the child-nodes existed or not /////
            if (((root->left)->left) != nullptr)
            {
                ///// Check if the current grand-parent node is even or not /////
                if (! ((root->val) % 2)) { res_sum_val += (((root->left)->left)->val); } //Keep updating, accumulating
            }

            if (((root->left)->right) != nullptr)
            {
                ///// Check if the current grand-parent node is even or not /////
                if (! ((root->val) % 2)) { res_sum_val += (((root->left)->right)->val); } //Keep updating, accumulating
            }

            dfsTraversal((root->left), res_sum_val); //Recursion function call (i.e. root left-half node)
        }

        if ((root->right) != nullptr)
        {
            ///// Check if the child-nodes existed or not /////
            if (((root->right)->left) != nullptr)
            {
                ///// Check if the current grand-parent node is even or not /////
                if (! ((root->val) % 2)) { res_sum_val += (((root->right)->left)->val); } //Keep updating, accumulating
            }

            if (((root->right)->right) != nullptr)
            {
                ///// Check if the current grand-parent node is even or not /////
                if (! ((root->val) % 2)) { res_sum_val += (((root->right)->right)->val); } //Keep updating, accumulating
            }

            dfsTraversal((root->right), res_sum_val); //Recursion function call (i.e. root right-half node)
        }
    }
};
