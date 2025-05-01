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
    vector<string> binaryTreePaths(TreeNode * root) 
    {
        //====================================//
        // Input type:                        //
        //   - TreeNode * (root tree-node)    //
        // Return type:                       //
        //   - vector<string> (result vector) //
        //====================================//

        /*Initialize*/
        ///// Result vector /////
        vector<string> res_vect;

        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root, to_string((root->val)), res_vect); //Recursion function call (i.e. whole root tree-node)

        return res_vect;
    }


    void dfsTraversal(TreeNode * root, string record_str, vector<string> & res_vect)
    {
        //=========================================//
        // Input type:                             //
        //   - TreeNode * (root tree-node)         //
        //   - string (record string)              //
        //   - vector<string> ref. (result vector) //
        // Return type:                            //
        //   - void (no return)                    //
        //=========================================//
        if (((root->left) == nullptr) && ((root->right) == nullptr)) //Issue, Boundary-case handling
        {
            res_vect.emplace_back(record_str); //Update, Record

            return;
        }

        /*Whole process, flow*/
        ///// Check if the current root left-half node existed or not /////
        if ((root->left) != nullptr)
        {
            dfsTraversal((root->left), (record_str + "->" + to_string(((root->left)->val))), res_vect); //Recursion function call (i.e. root left-half node)
        }

        ///// Check if the current root right-half node existed or not /////
        if ((root->right) != nullptr)
        {
            dfsTraversal((root->right), (record_str + "->" + to_string(((root->right)->val))), res_vect); //Recursion function call (i.e. root right-half node)
        }
    }
};
