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
    bool isEvenOddTree(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - bool (result flag)          //
        //=================================//

        /*Initialize*/
        ///// Odd flag /////
        bool odd_flag = true;

        ///// Record queue /////
        queue<TreeNode * > record_queue;


        /*Breath-first search based loop traversal*/
        record_queue.emplace(root); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            int record_val = (-1); //Record value

            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                TreeNode * record_root = record_queue.front(); record_queue.pop(); //Record root

                ///// Check if the current flag matched conditions or not /////
                if (odd_flag)
                {
                    ///// Check if the current indexed-value matched conditions or not /////
                    if (! ((record_root->val) % 2)) { return false; }

                    ///// Check if the current indexed-value is initialized or not /////
                    if (record_val == (-1)) { record_val = (record_root->val); } //Keep updating, overwriting
                    else
                    {
                        ///// Check if the current indexed-value matched conditions or not /////
                        if ((record_root->val) <= record_val) { return false; }

                        record_val = (record_root->val); //Keep updating, overwriting
                    }
                }
                else
                {
                    ///// Check if the current indexed-value matched conditions or not /////
                    if (((record_root->val) % 2)) { return false; }

                    ///// Check if the current indexed-value is initialized or not /////
                    if (record_val == (-1)) { record_val = (record_root->val); } //Keep updating, overwriting
                    else
                    {
                        ///// Check if the current indexed-value matched conditions or not /////
                        if ((record_root->val) >= record_val) { return false; }

                        record_val = (record_root->val); //Keep updating, overwriting
                    }
                }

                ///// Check if the root left-half node existed or not /////
                if ((record_root->left) != nullptr) { record_queue.emplace((record_root->left)); } //Keep updating, recording
                else { ; }

                ///// Check if the root right-half node existed or not /////
                if ((record_root->right) != nullptr) { record_queue.emplace((record_root->right)); } //Keep updating, recording
                else { ; }

            } //Queue-size

            odd_flag = (odd_flag) ? false : true; //Keep updating, overwriting

        } //Cycled-times

        return true;
    }
};
