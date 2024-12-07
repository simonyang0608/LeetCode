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
    int diameterOfBinaryTree(TreeNode * root) 
    {
        //==========================================//
        // Input type:                              //
        //   - TreeNode * (root tree-node)          //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//
        if (root && ((! (root->left)) && (! (root->right)))) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Result maximun summary counter /////
        int res_max_cnter = 0;

        /*Recursion-based DFS loop traversal*/
        int res_val = dfsTraversal(root, res_max_cnter); //Recursion function call (whole root node)

        return res_max_cnter;
    }


    int dfsTraversal(TreeNode * root, int & res_max_cnter)
    {
        //===============================================//
        // Input type:                                   //
        //   - TreeNode * (root tree-node)               //
        //   - int ref. (result maximun summary counter) //
        // Return type:                                  //
        //   - int (result maximun summary counter)      //
        //===============================================//
        if (! root) { return 0; } //Issue, Boundary-case handling

        if ((! root->left) && (! (root->right))) { return 1; } //Issue, Boundary-case handling


        /*Whole process, flow*/
        int record_left_cnter = dfsTraversal((root->left), res_max_cnter); //Recursion function call (root left-half node)
        int record_right_cnter = dfsTraversal((root->right), res_max_cnter); //Recursion function call (root right-half node)

        res_max_cnter = max(res_max_cnter, (record_left_cnter + record_right_cnter)); //Keep updating, overwriting

        return (1 + max(record_left_cnter, record_right_cnter));
    }
};
