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
    TreeNode * insertIntoBST(TreeNode * root, int val) 
    {
        //========================================//
        // Input type:                            //
        //   - TreeNode * (root tree-node)        //
        //   - int (inserted-value)               //
        // Return type:                           //
        //   - TreeNode * (result root tree-node) //
        //========================================//
        if (! root) { return new TreeNode(val); } //Issue, Boundary-case handling

        /*Recursion-based loop traversal*/
        ///// Check if the current inserted-value matched conditions or not /////
        if ((root->val) >= val)
        {
            (root->left) = insertIntoBST((root->left), val); //Recursion function call (i.e. root left-half node)
        }
        else
        {
            (root->right) = insertIntoBST((root->right), val); //Recursion function call (i.e. root right-half node)
        }

        return root;
    }
};
