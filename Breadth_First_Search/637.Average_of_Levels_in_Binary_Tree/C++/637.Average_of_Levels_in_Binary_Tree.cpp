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
    vector<double> averageOfLevels(TreeNode * root) 
    {
        //====================================//
        // Input type:                        //
        //   - TreeNode * (root tree-node)    //
        // Return type:                       //
        //   - vector<double> (result vector) //
        //====================================//

        /*Initialize*/
        ///// Record queue /////
        queue<TreeNode * > record_queue;

        ///// Result vector /////
        vector<double> res_vect;


        /*Breath-first search based loop traversal*/
        record_queue.emplace(root); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            int total_length = record_queue.size(); //Total length

            double total_sum_val = 0.0; //Total summary value

            for (int queue_idx = total_length; (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                TreeNode * record_root = record_queue.front(); record_queue.pop(); //Record root

                total_sum_val += (record_root->val); //Keep updating, accumulating

                ///// Check if the root left-half node existed or not /////
                if ((record_root->left) != nullptr)
                {
                    record_queue.emplace((record_root->left)); //Keep updating, recording
                }
                else { ; }

                ///// Check if the root right-half node existed or not /////
                if ((record_root->right) != nullptr)
                {
                    record_queue.emplace((record_root->right)); //Keep updating, accumulating
                }
                else { ; }

            } //Queue-size

            res_vect.emplace_back((total_sum_val / total_length)); //Keep updating, accumulating

        } //Cycled-times

        return res_vect;
    }
};
