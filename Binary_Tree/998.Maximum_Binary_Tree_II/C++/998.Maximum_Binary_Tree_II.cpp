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
    TreeNode * insertIntoMaxTree(TreeNode * root, int val) 
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - int (value)                   //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//
        
        /*Recursion-based loop traversal*/
        return recurseTraversal(root, val); //Recursion function call (whole root tree-node)
    }


    TreeNode * recurseTraversal(TreeNode * root, const int & val)
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - const int ref. (value)        //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//
        if ((root != nullptr) && ((root->val) > val)) //Issue, Boundary-case handling
        {
            (root->right) = recurseTraversal((root->right), val); //Recursion function call (i.e. root right-half node)

            return root;
        }

        return new TreeNode(val, root, nullptr);
    }
};
