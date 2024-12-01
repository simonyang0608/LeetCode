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
    TreeNode * trimBST(TreeNode * root, int low, int high) 
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - int (lower bound)             //
        //   - int (higher bound)            //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//

        return dfsTraversal(root, low, high); //Recursion function call (i.e. whole root node)
    }


    TreeNode * dfsTraversal(TreeNode * root, int & low, int & high)
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - int ref. (lower bound)        //
        //   - int ref. (higher bound)       //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//
        if (! root) { return NULL; } //Issue, Boundary-case handling

        if ((((root->val) >= low) && ((root->val) <= high)) && ((! (root->left)) && (! (root->right)))) { return root; } //Issue, Boundary-case handling


        /*Recursion-based DFS loop traversal*/
        (root->left) = dfsTraversal((root->left), low, high); //Recursion function call (i.e. root left-half node)
        (root->right) = dfsTraversal((root->right), low, high); //Recursion function call (i.e. root right-half node)

        ///// Check if the current node value matched conditions or not /////
        if (((root->val) < low) || ((root->val) > high))
        {
            ///// Check if the current root left, right-half node existed or not /////
            if ((root->right)) { return successor(root); }
            else if ((root->left)) { return preceedor(root); }

            return NULL;
        }

        return root;
    }


    TreeNode * successor(TreeNode * root)
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//

        /*Initialize*/
        ///// Result root tree-node /////
        TreeNode * res_root_right, * root_left = (root->left), * root_right = (root->right);
        res_root_right = root_right;

        /*Whole process, flow*/
        ///// Check if the current root left, right-half node existed or not /////
        if ((root->left)) { (root->left) = NULL; } //Update, Overwrite
        else { ; }

        (root->right) = NULL; //Update, Overwrite

        while ((root_right->left)) { root_right = (root_right->left); } //Update, Overwrite

        (root_right->left) = root_left; //Update, Overwrite

        return res_root_right;
    }


    TreeNode * preceedor(TreeNode * root)
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        // Return type:                      //
        //   - TreeNode * (result tree-node) //
        //===================================//

        /*Whole process, flow*/
        TreeNode * res_root_left = (root->left); //Result root left-half node

        (root->left) = NULL; //Update, Overwrite

        return res_root_left;
    }
};
