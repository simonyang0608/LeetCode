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
    void dfsTraversal(TreeNode * root, vector<int> & res_vect)
    {
        //======================================//
        // Input type:                          //
        //   - TreeNode * (root tree-node)      //
        //   - vector<int> ref. (result vector) //
        // Return type:                         //
        //   - void (no return)                 //
        //======================================//
        if (! root) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        dfsTraversal((root->left), res_vect); //Recursion function call (i.e. root left-half node)

        res_vect.push_back((root->val)); //Update, Record

        dfsTraversal((root->right), res_vect); //Recursion function call (i.e. root right-half node)
    }


    vector<int> inorderTraversal(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initalize*/
        ///// Result vector /////
        vector<int> res_vect;

        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, res_vect); //Recursion function call (i.e. whole node)

        return res_vect;
    }
};
