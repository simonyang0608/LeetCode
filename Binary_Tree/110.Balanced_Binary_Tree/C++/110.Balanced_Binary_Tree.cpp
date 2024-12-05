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
    bool isBalanced(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - bool (result flag)          //
        //=================================//
        if (! root) { return true; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record flag /////
        bool record_flag = true;

        /*Recursion-based DFS loop traversal*/
        int res_height = dfsTraversal(root, record_flag); //Recursion function call (i.e. whole root node)

        return record_flag;
    }


    int dfsTraversal(TreeNode * root, bool & record_flag)
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        //   - bool ref. (record flag)     //
        // Return type:                    //
        //   - int (result maximun height) //
        //=================================//
        if (! root) { return 0; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        int root_left_height = dfsTraversal((root->left), record_flag); //Recursion function call (i.e. root left-half node)
        int root_right_height = dfsTraversal((root->right), record_flag); //Recursion function call (i.e. root right-half node)

        ///// Check if the current height differences matched conditions or not /////
        if (abs(root_left_height - root_right_height) > 1)
        {
            if (record_flag) { record_flag &= false; } //Update, Overwrite
        }

        return (max(root_left_height, root_right_height) + 1);
    }
};
