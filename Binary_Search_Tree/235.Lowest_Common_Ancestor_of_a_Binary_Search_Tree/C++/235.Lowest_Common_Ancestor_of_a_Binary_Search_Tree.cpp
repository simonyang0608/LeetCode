/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * p, TreeNode * q) 
    {
        //========================================//
        // Input type:                            //
        //   - TreeNode * (root tree-node)        //
        //   - TreeNode * (p tree-node)           //
        //   - TreeNode * (q tree-node)           //
        // Return type:                           //
        //   - TreeNode * (result root tree-node) //
        //========================================//

        /*Initialize*/
        ///// Record maximun value of child-nodes /////
        int record_max_val = ((p->val) > (q->val)) ? (p->val) : (q->val);

        ///// Record minimun value of child-nodes /////
        int record_min_val = ((p->val) < (q->val)) ? (p->val) : (q->val);


        /*Binary-search based loop traversal*/
        while (root != nullptr) //Binary-search
        {
            ///// Check if the current root-node value matched conditions or not /////
            if ((root->val) < record_min_val) { root = (root->right); } //Keep updating, traversing

            else if ((root->val) > record_max_val) { root = (root->left); } //Keep updating, traversing

            else { return root; }

        } //Binary-search

        return nullptr;
    }
};
