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
    void bfsTraversal(TreeNode * root, int level, vector<vector<int>> & res_vect)
    {
        //==============================================//
        // Input type:                                  //
        //   - TreeNode * (root tree-node)              //
        //   - int (n-th level)                         //
        //   - vector<vector<int>> ref. (result vector) //
        // Return type:                                 //
        //   - void (no return)                         //
        //==============================================//
        if (! root) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        ///// Step 1: Check if the current level matched conditions or not /////
        if (res_vect.size() < level) { res_vect.push_back({(root->val)}); } //Update, Record
        else { (res_vect[(level - 1)]).push_back((root->val)); } //Update, Record

        ///// Step 2: Recursion-based BFS loop traversal /////
        bfsTraversal((root->left), (level + 1), res_vect); //Recursion function call (i.e. root left-half node)
        bfsTraversal((root->right), (level + 1), res_vect); //Recursion function call (i.e. root right-half node)
    }


    vector<vector<int>> levelOrder(TreeNode * root) 
    {
        //=========================================//
        // Input type:                             //
        //   - TreeNode * (root tree-node)         //
        // Return type:                            //
        //   - vector<vector<int>> (result vector) //
        //=========================================//

        /*Initialize*/
        ///// Result vector /////
        vector<vector<int>> res_vect;

        /*Recursion-based BFS loop traversal*/
        bfsTraversal(root, 1, res_vect); //Recursion function call (i.e. whole node)

        return res_vect;
    }
};
