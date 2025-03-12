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
    bool leafSimilar(TreeNode * root1, TreeNode * root2) 
    {
        //==================================//
        // Input type:                      //
        //   - TreeNode * (root1 tree-node) //
        //   - TreeNode * (root2 tree-node) //
        // Return type:                     //
        //   - bool (result flag)           //
        //==================================//

        /*Initialize*/
        ///// Record vectors (i.e. 1, 2) /////
        vector<int> record_vect1, record_vect2;

        /*Recursion-based DFS loop traversal*/
        dfsTraversal(root1, record_vect1); dfsTraversal(root2, record_vect2); //Recursion function call (i.e. whole root tree-node)

        ///// Check if the current vector is the same or not /////
        if (record_vect1 == record_vect2) { return true; }

        return false;
    }


    void dfsTraversal(TreeNode * root, vector<int> & record_vect)
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (root tree-node)   //
        //   - vector<int> & (record vector) //
        // Return type:                      //
        //   - void (no return)              //
        //===================================//
        if (root == nullptr) { return; } //Issue, Boundary-case handling

        if (((root->left) == nullptr) && ((root->right) == nullptr)) //Issue, Boundary-case handling
        {
            record_vect.emplace_back((root->val)); //Update, Record

            return;
        }

        dfsTraversal((root->left), record_vect); //Recursion function call (i.e. root left-half node)
        dfsTraversal((root->right), record_vect); //Recursion function call (i.e. root right-half node)
    }
};
