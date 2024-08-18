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
    TreeNode * invertTree(TreeNode * root)
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root node)        //
        // Return type:                      //
        //   - TreeNode * (result root node) //
        //===================================//
        if (! root) { return NULL; } //Issue, Boundary-case handling

        if ((! (root->left)) && (! (root->right))) { return root; } //Issue, Boundary-case handling


        /*Recursion-based DFS loop traversal*/
        TreeNode * tmp_node = (root->left); //Temporal node

        (root->left) = invertTree((root->right)); //Recursion function call (i.e. root left-half node)
        (root->right) = invertTree(tmp_node); //Recursion function call (i.e. root right-half node)

        return root;
    }
};
