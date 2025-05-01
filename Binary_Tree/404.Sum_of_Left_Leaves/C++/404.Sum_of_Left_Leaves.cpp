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
    int sumOfLeftLeaves(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - int (result summary value)  //
        //=================================//

        /*Initialize*/
        ///// Record queue /////
        queue<TreeNode * > record_queue;

        ///// Result summary value /////
        int res_sum_val = 0;


        /*Breath-first search based loop traversal*/
        record_queue.emplace(root); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                TreeNode * record_root = record_queue.front(); record_queue.pop(); //Record root

                ///// Check if the next root left-half node existed or not /////
                if ((record_root->left) != nullptr)
                {
                    ///// Check if the root child-child node existed or not /////
                    if ((((record_root->left)->left) == nullptr) && (((record_root->left)->right) == nullptr))
                    {
                        res_sum_val += ((record_root->left)->val); //Keep updating, accumulating
                    }
                    else { ; }

                    record_queue.emplace((record_root->left)); //Keep updating, recording
                }
                else { ; }

                ///// Check if the next root right-half node existed or not /////
                if ((record_root->right) != nullptr) { record_queue.emplace((record_root->right)); } //Keep updating, recording
                else { ; }

            } //Queue-size

        } //Cycled-times

        return res_sum_val;
    }
};
