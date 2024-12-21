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
    int maxPathSum(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - int (result maximun path)   //
        //=================================//

        /*Initialize*/
        ///// Result maximun path /////
        int res_max_path = (((-3) * 1e7) - 1);

        /*Recursion-based DFS loop traversal*/
        int record_max_path = dfsTraversal(root, res_max_path); //Recursion function call (i.e. whole root node)

        return res_max_path;
    }


    int dfsTraversal(TreeNode * root, int & res_max_path)
    {
        //====================================//
        // Input type:                        //
        //   - TreeNode * (root tree-node)    //
        //   - int ref. (result maximun path) //
        // Return type:                       //
        //   - int (record maximun path)      //
        //====================================//
        if (! root) { return 0; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        int root_left_path = dfsTraversal((root->left), res_max_path); //Recursion function call (i.e. root left-half node)
        int root_right_path = dfsTraversal((root->right), res_max_path); //Recursion function call (i.e. root right-half node)

        res_max_path = max({res_max_path, (root->val), ((root->val) + root_left_path), ((root->val) + root_right_path), ((root->val) + root_left_path + root_right_path)}); //Update, Overwrite

        return max((root->val), ((root->val) + max(root_left_path, root_right_path)));
    }
};
