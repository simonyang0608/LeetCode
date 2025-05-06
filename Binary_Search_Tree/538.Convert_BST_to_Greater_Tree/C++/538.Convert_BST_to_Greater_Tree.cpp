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
    TreeNode * convertBST(TreeNode * root) 
    {
        //========================================//
        // Input type:                            //
        //   - TreeNode * (root tree-node)        //
        // Return type:                           //
        //   - TreeNode * (result root tree-node) //
        //========================================//
        if (root == nullptr) { return nullptr; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record summary value /////
        int record_sum_val = 0;

        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, record_sum_val); //Recursion function call (i.e. whole root tree-node)

        return root;
    }


    void dfsTraversal(TreeNode * root, int & record_sum_val)
    {
        //=====================================//
        // Input type:                         //
        //   - TreeNode * (root tree-node)     //
        //   - int ref. (record summary value) //
        // Return type:                        //
        //   - void (no return)                //
        //=====================================//
        if (root == nullptr) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        dfsTraversal((root->right), record_sum_val); //Recursion function call (i.e. root right-half node)

        record_sum_val += (root->val); //Update, Accumulate

        (root->val) = record_sum_val; //Update, Overwrite

        dfsTraversal((root->left), record_sum_val); //Recursion function call (i.e. root left-half node)
    }
};
