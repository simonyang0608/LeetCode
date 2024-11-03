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
    int kthSmallest(TreeNode * root, int k) 
    {
        //==================================//
        // Input type:                      //
        //   - TreeNode * (root tree-node)  //
        //   - int (k-th smallest order)    //
        // Return type:                     //
        //   - int (result tree-node value) //
        //==================================//

        /*Initialize*/
        ///// Record stack /////
        stack<TreeNode * > record_stack;

        ///// Record root tree-node /////
        TreeNode * record_root;


        /*Stack-based loop traversal*/
        while (root || (! record_stack.empty())) //Iterative
        {
            while (root) //Left-half tree-node
            {
                record_stack.push(root); //Keep updating, recording

                root = (root->left); //Keep updating, overwriting

            } //Left-half tree-node

            record_root = record_stack.top(); //Record root tree-node

            record_stack.pop(); //Popped from the last element

            (k--); //Keep updatating, reducing

            ///// Check if the current order matched conditions or not /////
            if (! k) { return (record_root->val); }

            root = (record_root->right); //Keep updating, overwriting

        } //Iterative

        return (-1);
    }
};
