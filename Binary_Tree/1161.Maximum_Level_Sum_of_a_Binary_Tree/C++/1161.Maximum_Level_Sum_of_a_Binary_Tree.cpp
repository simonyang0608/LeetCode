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
    int maxLevelSum(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - int (result index)          //
        //=================================//

        /*Initialize*/
        ///// Record vector /////
        vector<vector<int>> record_vect;

        ///// Result maximun value /////
        int res_max_val = (((-1) * 1e5) -1);


        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, record_vect, 1); //Recursion function call (Whole root tree-node)

        for (int record_idx = 0; (record_idx < record_vect.size()); (record_idx++)) //Whole
        {
            ///// Check if the current summary value is larger or not /////
            if ((record_vect[record_idx])[0] > res_max_val) { res_max_val = (record_vect[record_idx])[0]; } //Keep updating, overwriting
            else { ; }

        } //Whole

        for (int record_idx = 0; (record_idx < record_vect.size()); (record_idx++)) //Whole
        {
            ///// Check if the current summary value matched conditions or not /////
            if ((record_vect[record_idx])[0] == res_max_val) { return (record_idx + 1); }

        } //Whole

        return (-1);
    }


    void dfsTraversal(TreeNode * root, vector<vector<int>> & record_vect, int record_level)
    {
        //==============================================//
        // Input type:                                  //
        //   - TreeNode * (root tree-node)              //
        //   - vector<vector<int>> ref. (record vector) //
        //   - int (record index)                       //
        // Return type:                                 //
        //   - void (no return)                         //
        //==============================================//
        if (root == nullptr) { return; } //Issue, Boundary-case handling

        ///// Check if the current level exceeds boundary or not /////
        if (record_level > record_vect.size()) { record_vect.push_back({(root->val)}); } //Update, Record
        else { (record_vect[(record_level - 1)])[0] += (root->val); } //Update, Overwrite

        dfsTraversal((root->left), record_vect, (record_level + 1)); //Recursion function call (root left-half node)
        dfsTraversal((root->right), record_vect, (record_level + 1)); //Recursion function call (root right-half node)
    }
};
