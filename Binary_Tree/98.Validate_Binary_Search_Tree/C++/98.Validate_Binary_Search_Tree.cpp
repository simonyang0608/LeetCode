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
    bool isValidBST(TreeNode * root)
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - bool (result flag)          //
        //=================================//

        /*Initialize*/
        ///// Record value /////
        long long record_val = (((-1) * (static_cast<long long>(1) << 31)) - 1);

        ///// Record flag /////
        bool record_flag = true;


        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, record_val, record_flag); //Recursion function call (i.e. whole root tree-node)

        return record_flag;
    }


    void dfsTraversal(TreeNode * root, long long & record_val, bool & record_flag)
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - long long ref. (record value) //
        //   - bool ref. (record flag)       //
        // Return type:                      //
        //   - void (no return)              //
        //===================================//
        if (root == nullptr) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        dfsTraversal((root->left), record_val, record_flag); //Recursion function call (i.e. root left-half node)

        ///// Check if the current value is larger or not /////
        if ((root->val) <= record_val)
        {
            ///// Check if the current flag needs to be overwrited or not /////
            if (record_flag) { record_flag &= false; } //Update, Overwrite
            else { ; }
        }
        else { ; }

        record_val = (root->val); //Update, Overwrite

        dfsTraversal((root->right), record_val, record_flag); //Recursion function call (i.e. root right-half node)
    }
};
