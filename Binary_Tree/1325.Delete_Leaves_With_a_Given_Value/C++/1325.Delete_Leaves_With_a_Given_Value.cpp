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
    TreeNode * dfsTraversal(TreeNode * root, int target) 
    {
        //========================================//
        // Input type:                            //
        //    - TreeNode * (root tree-node)       //
        //    - int (target value)                //
        // Return type:                           //
        //   - TreeNode * (result root tree-node) //
        //========================================//
        if (! root) { return NULL; } //Issue, Boundary-case handling
        if ((! root->left) && (! root->right)) //Issue, Boundary-case handling
        {
            if (root->val == target) { return NULL; }

            return root;
        }

        /*Whole process, flow*/
        root->left = dfsTraversal(root->left, target); //Recursion function call (i.e. root left-half node)
        root->right = dfsTraversal(root->right, target); //Recursion function call (i.e. root right-half node)

        if ((! root->left) && (! root->right)) //Issue, Boundary-case handling
        {
            if (root->val == target) { return NULL; }

            return root;
        }

        return root;
    }

    TreeNode * removeLeafNodes(TreeNode * root, int target) 
    {
        //========================================//
        // Input type:                            //
        //    - TreeNode * (root tree-node)       //
        //    - int (target value)                //
        // Return type:                           //
        //   - TreeNode * (result root tree-node) //
        //========================================//

        return dfsTraversal(root, target); //Recursion function call (i.e. root whole node)
    }
};
