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
    vector<int> rightSideView(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// Record vector /////
        vector<vector<int>> record_vect;

        ///// Length of record vector /////
        int len_record_vect;

        ///// Result vector /////
        vector<int> res_vect;


        /*Recursion-based BFS loop traversal*/
        ///// Step 1: Recursion function call for the whole tree-node /////
        bfsTraversal(root, record_vect, 1);

        ///// Step 2: Post-process, Final completions /////
        len_record_vect = record_vect.size(); //Length of record vector

        for (int record_vect_idx = 0; (record_vect_idx < len_record_vect); (record_vect_idx++)) //Whole
        {
            res_vect.emplace_back((record_vect[record_vect_idx]).back()); //Keep updating, recording

        } //Whole

        return res_vect;
    }


    void bfsTraversal(TreeNode * root, vector<vector<int>> & record_vect, int level)
    {
        //==============================================//
        // Input type:                                  //
        //   - TreeNode * (root tree-node)              //
        //   - vector<vector<int>> ref. (record vector) //
        //   - int (total level)                        //
        // Return type:                                 //
        //   - void (no return)                         //
        //==============================================//
        if (! root) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        ///// Check if the current level matched conditions or not /////
        if (record_vect.size() < level) { record_vect.push_back({ (root->val) }); } //Keep updating, recording
        else { (record_vect[(level - 1)]).push_back((root->val)); } //Keep updating, recording

        bfsTraversal((root->left), record_vect, (level + 1)); //Recursion function call (i.e. root left-half node)
        bfsTraversal((root->right), record_vect, (level + 1)); ////Recursion function call (i.e. root right-half node)
    }
};
