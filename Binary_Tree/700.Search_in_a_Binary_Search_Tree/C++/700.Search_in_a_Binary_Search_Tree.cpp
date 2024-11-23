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
    TreeNode * searchBST(TreeNode * root, int val) 
    {
        //===================================// 
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - int (target value)            //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//

        return recurseTraversal(root, val); //Recursion function call
    }


    TreeNode * recurseTraversal(TreeNode * root, int & val)
    {
        //===================================// 
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - int ref. (target value)       //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//
        if (! root) { return NULL; } //Issue, Boundary-case handling

        if ((root->val) == val) { return root; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        ///// Check if the current tree-node value matched conditions or not /////
        if ((val >= (root->val))) { return recurseTraversal((root->right), val); } //Recursion function call (i.e. root right-half node)
        else { return recurseTraversal((root->left), val); } //Recursion function call (i.e. root left-half node)
    }
};
