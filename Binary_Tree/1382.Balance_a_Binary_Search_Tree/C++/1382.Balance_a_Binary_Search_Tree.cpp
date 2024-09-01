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
        //   - TreeNode * (root node)           //
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


    TreeNode * treeTraversal(int left_low, int right_high, vector<int> & res_vect)
    {
        //======================================//
        // Input type:                          //
        //   - int (left-low index)             //
        //   - int (right-high index)           //
        //   - vector<int> ref. (result vector) //
        // Return type:                         //
        //   - TreeNode * (result root node)    //
        //======================================//
        if (left_low > right_high) { return NULL; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Middle index /////
        int middle = ((left_low + right_high) / 2);

        /*Whole process, flow*/
        TreeNode * root = new TreeNode(res_vect[middle]); //Root node

        (root->left) = treeTraversal(left_low, (middle - 1), res_vect); //Recursion function call (i.e. root left-half node)
        (root->right) = treeTraversal((middle + 1), right_high, res_vect); //Recursion function call (i.e. root right-half node)

        return root;
    }


    TreeNode * balanceBST(TreeNode * root) 
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root node)        //
        // Return type:                      //
        //   - TreeNode * (result root node) //
        //===================================//

        /*Initialize*/
        ///// Result vector /////
        vector<int> res_vect;

        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, res_vect); //Recursion function call (i.e. whole node)

        return treeTraversal(0, (res_vect.size() - 1), res_vect);
    }
};
