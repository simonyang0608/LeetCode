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
    void dfsTraversal(TreeNode * root, vector<TreeNode * > & res_vect)
    {
        //=========================================//
        // Input type:                             //
        //   - TreeNode * (root tree-node)         //
        //   - vector<TreeNode * > (result vector) //
        // Return type:                            //
        //   - void (i.e. no return)               //
        //=========================================//
        if (! root) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        TreeNode * root_left = (root->left), * root_right = (root->right); //Root left, right-half node

        (root->left) = NULL; //Update, Overwrite
        (root->right) = NULL; //Update, Overwrite

        res_vect.emplace_back(root); //Update, Record

        dfsTraversal(root_left, res_vect); //Recursion function call (i.e. root left-half node)
        dfsTraversal(root_right, res_vect); //Recursion function call (i.e. root right-half node)
    }


    void flatten(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - void (i.e. no return)       //
        //=================================//

        /*Initialize*/
        ///// Length of result vector /////
        int len_res_vect;

        ///// Result vector /////+
        vector<TreeNode * > res_vect;


        /*Recursion-based DFS traversal method*/
        dfsTraversal(root, res_vect); //Recursion function call (i.e. whole node)

        len_res_vect = (res_vect.size()); //Length of result vector
        (len_res_vect--); //Update, Reduce

        for (int res_vect_idx = 0; (res_vect_idx < len_res_vect); (res_vect_idx++)) //Whole
        {
            ((res_vect[res_vect_idx])->right) = res_vect[(res_vect_idx + 1)]; //Keep updating, overwriting

        } //Whole
    }
};
