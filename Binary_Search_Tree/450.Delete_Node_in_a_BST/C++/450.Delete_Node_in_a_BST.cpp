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
    TreeNode * deleteNode(TreeNode * root, int key) 
    {
        //========================================//
        // Input type:                            //
        //   - TreeNode * (tree-node root)        //
        //   - int (key target value)             //
        // Return type:                           //
        //   - TreeNode * (result tree-node root) //
        //========================================//
        if (! root) { return NULL; } //Issue, Boundary-case handling

        /*Recursion-based loop traversal*/
        ///// Root right-half tree-node search /////
        if ((root->val) < key) { (root->right) = deleteNode((root->right), key); }

        ///// Root left-half tree-node search /////
        else if ((root->val) > key) { (root->left) = deleteNode((root->left), key); }

        ///// Target tree-node search /////
        else
        {
            if ((! root->left) && (! (root->right))) { root = NULL; } //Leaf tree-node

            else if ((root->right)) //Sub-root right-half tree-node search
            {
                (root->val) = successor(root); //Update, Overwrite
                (root->right) = deleteNode((root->right), (root->val)); //Update, Overwrite
            }

            else //Sub-root left-half tree-node search
            {
                (root->val) = preceedor(root); //Update, Overwrite
                (root->left) = deleteNode((root->left), (root->val)); //Update, Overwrite
            }
        }

        return root;
    }


    int successor(TreeNode * root)
    {
        //=======================================//
        // Input type:                           //
        //   - TreeNode * (tree-node root)       //
        // Return type:                          //
        //   - int (result tree-node root value) //
        //=======================================//

        /*Initialize*/
        ///// Root right-half tree-node /////
        TreeNode * root_right = (root->right);

        /*Whole process, flow*/
        while ((root_right->left)) //Whole
        {
            (root_right) = (root_right->left); //Keep updating, overwriting

        } //Whole

        return (root_right->val);
    }


    int preceedor(TreeNode * root)
    {
        //=======================================//
        // Input type:                           //
        //   - TreeNode * (tree-node root)       //
        // Return type:                          //
        //   - int (result tree-node root value) //
        //=======================================//

        /*Initialize*/
        ///// Root left-half tree-node /////
        TreeNode * root_left = (root->left);

        /*Whole process, flow*/
        while ((root_left->right)) //Whole
        {
            (root_left) = (root_left->right); //Keep updating, overwriting

        } //Whole

        return (root_left->val);
    }
};
