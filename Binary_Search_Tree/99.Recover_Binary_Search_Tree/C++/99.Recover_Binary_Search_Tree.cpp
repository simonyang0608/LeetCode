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
    void recoverTree(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - void (no return)            //
        //=================================//

        /*Initialize*/
        ///// Record stack /////
        stack<TreeNode * > record_stack;

        ///// Previous root tree-node /////
        TreeNode * prev_node = nullptr;

        ///// Result first, second root tree-node /////
        TreeNode * res_first_node = nullptr, * res_second_node = nullptr;


        /*Stack-based loop traversal*/
        while ((! record_stack.empty()) || (root != nullptr)) //Whole
        {
            while (root != nullptr) //Part
            {
                record_stack.emplace(root); //Keep updating, recording

                root = (root->left); //Keep updating, traversing

            } //Part

            ///// Check if the current root tree-node existed or not /////
            if (prev_node == nullptr) { ; }
            else
            {
                ///// Check if the current tree-node value matched conditions or not /////
                if ((prev_node->val) > ((record_stack.top())->val))
                {
                    ///// Check if the current tree-node existed or not /////
                    if (res_first_node == nullptr) { res_first_node = prev_node; } //Keep updating, overwriting
                    else { ; }

                    res_second_node = record_stack.top(); //Keep updating, overwriting
                }
            }

            prev_node = record_stack.top(); record_stack.pop(); //Keep updating, popped

            root = (prev_node->right); //Keep updating, traversing

        } //Whole

        swap((res_first_node->val), (res_second_node->val)); //Swapped operations
    }
};
