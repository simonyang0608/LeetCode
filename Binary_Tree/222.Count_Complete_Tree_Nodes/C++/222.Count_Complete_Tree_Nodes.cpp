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
    int countNodes(TreeNode * root) 
    {
        //==================================//
        // Input type:                      //
        //   - TreeNode * (root tree-node)  //
        // Return type:                     //
        //   - int (result summary counter) //
        //==================================//
        if (! root) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record vector /////
        vector<TreeNode * > record_vect;

        record_vect.emplace_back(root);

        ///// Length of vector /////
        int len_vect = 1;

        ///// Record tree-node /////
        TreeNode * record_node;

        ///// Record traversal index /////
        int record_traversal_idx = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Queue-based loop traversal*/
        while (record_traversal_idx < len_vect) //Whole
        {
            record_node = record_vect[record_traversal_idx]; //Record tree-node

            (res_cnter++); //Keep updating, accumulating

            ///// Check if the current tree-node matched conditions or not /////
            if ((record_node->left)) //Left-half
            {
                record_vect.emplace_back((record_node->left)); //Keep updating, recording

                (len_vect++); //Keep updating, accumulating
            }
            else { ; }

            if ((record_node->right)) //Right-half
            {
                record_vect.emplace_back((record_node->right)); //Keep updating, recording

                (len_vect++); //Keep updating, accumulating
            }
            else { ; }

            (record_traversal_idx++); //Keep updating, accumulating

        } //Whole

        return res_cnter;
    }
};
