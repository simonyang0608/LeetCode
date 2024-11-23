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
    int longestZigZag(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - int (result maximun path)   //
        //=================================//
        if ((! (root->left)) && (! (root->right))) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Result maximun path /////
        int res_max_path = 0;

        /*Recursion-based DFS loop traversal*/
        ///// Check if the next tree-node (i.e. left, right-half) existed or not /////
        if ((root->left))
        {
            dfsTraversal((root->left), 0, 1, res_max_path); //Recursion function call (i.e. root left-half node)
        }

        if ((root->right))
        {
            dfsTraversal((root->right), 1, 1, res_max_path); //Recursion function call (i.e. root right-half node)
        }

        return res_max_path;
    }


    void dfsTraversal(TreeNode * root, bool record_direc, int record_path, int & res_max_path)
    {
        //====================================//
        // Input type:                        //
        //   - TreeNode * (root tree-node)    //
        //   - bool (record direction)        //
        //   - int (record path)              //
        //   - int ref. (result maximun path) //
        // Return type:                       //
        //   - void (no return)               //
        //====================================//
        if (record_path > res_max_path) { res_max_path = record_path; } //Update, Overwrite

        /*Whole process, flow*/
        ///// Check if the current direction is left or right /////
        if (! record_direc)
        {
            ///// Check if the next tree-node (i.e. left, right-half) existed or not /////
            if ((root->right))
            {
                dfsTraversal((root->right), 1, (record_path + 1), res_max_path); //Recursion function call (i.e. root right-half node)
            }

            if ((root->left))
            {
                dfsTraversal((root->left), 0, 1, res_max_path); //Recursion function call (i.e. root left-half node)
            }
        }

        else
        {
            ///// Check if the next tree-node (i.e. left, right-half) existed or not /////
            if ((root->right))
            {
                dfsTraversal((root->right), 1, 1, res_max_path); //Recursion function call (i.e. root right-half node)
            }

            if ((root->left))
            {
                dfsTraversal((root->left), 0, (record_path + 1), res_max_path); //Recursion function call (i.e. root left-half node)
            }
        }
    }
};
