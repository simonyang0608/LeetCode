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
    int minDepth(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - int (result minimun depth)  //
        //=================================//
        if (root == nullptr) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Result minimun depth /////
        int res_min_depth = (1e5 + 1);

        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, 1, res_min_depth); //Recursion function call (i.e. whole root tree-node)

        return res_min_depth;
    }


    void dfsTraversal(TreeNode * root, int record_depth, int & res_min_depth)
    {
        //=====================================//
        // Input type:                         //
        //   - TreeNode * (root tree-node)     //
        //   - int (record depth)              //
        //   - int ref. (result minimun depth) //
        // Return type:                        //
        //   - void (no return)                //
        //=====================================//
        if (root == nullptr) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        ///// Check if the current root matched conditions or not /////
        if (((root->left) == nullptr) && ((root->right) == nullptr))
        {
            res_min_depth = (record_depth < res_min_depth) ? record_depth : res_min_depth; //Update, Overwrite

            return;
        }

        dfsTraversal((root->left), (record_depth + 1), res_min_depth); //Recursion function call (i.e. root left-half node)
        dfsTraversal((root->right), (record_depth + 1), res_min_depth); //Recursion function call (i.e. root right-half node)
    }
};
