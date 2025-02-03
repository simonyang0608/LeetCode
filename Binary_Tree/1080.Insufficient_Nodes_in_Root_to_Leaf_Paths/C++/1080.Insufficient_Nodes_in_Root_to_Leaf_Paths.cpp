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
    TreeNode * sufficientSubset(TreeNode * root, int limit) 
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - int (limit value)             //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//

        return dfsTraversal(root, (root->val), limit); //Recursion function call (i.e. whole root tree-node)
    }


    TreeNode * dfsTraversal(TreeNode * root, int record_val, const int & limit)
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - int (record value)            //
        //   - const int ref. (limit value)  //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//
        if (((root->left) == nullptr) && ((root->right) == nullptr)) //Issue, Boundary-case handling
        {
            ///// Check if the current value matched conditions or not /////
            if (record_val < limit) { return nullptr; }

            return root;
        }

        /*Whole process, flow*/
        ///// Check if the next root tree-node is null or not /////
        if ((root->left) != nullptr)
        {
            (root->left) = dfsTraversal((root->left), (record_val + ((root->left)->val)), limit); //Recursion function call (i.e. root left-half node)
        }

        if ((root->right) != nullptr)
        {
            (root->right) = dfsTraversal((root->right), (record_val + ((root->right)->val)), limit); //Recursion function call (i.e. root left-half node)
        }

        if (((root->left) == nullptr) && ((root->right) == nullptr)) { root = nullptr; } //Update, Overwrite

        return root;
    }
};
