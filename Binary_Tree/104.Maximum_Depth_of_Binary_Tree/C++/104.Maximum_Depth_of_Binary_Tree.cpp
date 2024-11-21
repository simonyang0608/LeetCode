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
    int maxDepth(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - int (result maximun depth)  //
        //=================================//
        if (! root) { return 0; } //Issue, Boundary-case handling

        if ((! (root->left)) && (! (root->right))) { return 1; } //Issue, Boundary-case handling

        /*Recursion-based DFS loop traversal*/
        int left_height = maxDepth((root->left)); //Recursion function call (i.e. root left-half node)
        int right_height = maxDepth((root->right)); //Recursion function call (i.e. root right-half node)

        return (max(left_height, right_height) + 1);
    }
};
