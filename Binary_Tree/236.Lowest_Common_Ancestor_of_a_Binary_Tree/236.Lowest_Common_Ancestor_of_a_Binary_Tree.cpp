/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) 
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - TreeNode * (p tree-node)      //
        //   - TreeNode * (q tree-node)      //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//

        return dfsTraversal(root, p, q); //Recursion function call (i.e. whole root tree-node)
    }


    TreeNode * dfsTraversal(TreeNode * root, TreeNode * p, TreeNode * q)
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - TreeNode * (p tree-node)      //
        //   - TreeNode * (q tree-node)      //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//
        if ((root == nullptr) || (root == p) || (root == q)) { return root; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        TreeNode * root_left = dfsTraversal((root->left), p, q); //Recursion function call (i.e. root left-half node)
        TreeNode * root_right = dfsTraversal((root->right), p, q); //Recursion function call (i.e. root right-half node)

        ///// Check if the current sub root tree-node matched condtions or not /////
        if (root_left && root_right) { return root; }

        if (root_left) { return root_left; }
        if (root_right) { return root_right; }

        return root_left;
    }
};
