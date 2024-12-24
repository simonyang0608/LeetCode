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
    int getMinimumDifference(TreeNode * root) 
    {
        //=====================================//
        // Input type:                         //
        //   - TreeNode * (root tree-node)     //
        // Return type:                        //
        //   - int (result minimun difference) //
        //=====================================//

        /*Initialize*/
        ///// Record vector /////
        vector<int> record_vect;

        ///// Result minimun difference /////
        int res_min_diff = (1e9 + 1);


        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, record_vect); //Recursion function call

        for (int record_idx = 0; (record_idx < (record_vect.size() - 1)); (record_idx++)) //Whole
        {
            res_min_diff = min(res_min_diff, abs(record_vect[record_idx] - record_vect[(record_idx + 1)])); //Keep updating, overwriting

        } //Whole

        return res_min_diff;
    }


    void dfsTraversal(TreeNode * root, vector<int> & record_vect)
    {
        //======================================//
        // Input type:                          //
        //   - TreeNode * (root tree-node)      //
        //   - vector<int> ref. (record vector) //
        // Return type:                         //
        //   - void (no return)                 //
        //======================================//
        if (! root) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        dfsTraversal((root->left), record_vect); //Recursion function call (i.e. root left-half node)

        record_vect.emplace_back((root->val)); //Update, Record

        dfsTraversal((root->right), record_vect); //Recursion function call (i.e. root right-half node)
    }
};
