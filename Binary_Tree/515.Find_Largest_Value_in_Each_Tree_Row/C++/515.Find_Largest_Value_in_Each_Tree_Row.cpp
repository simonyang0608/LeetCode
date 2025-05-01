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
    vector<int> largestValues(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//
        if (root == nullptr) { return {}; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record queue /////
        queue<TreeNode * > record_queue;

        ///// Result vector /////
        vector<int> res_vect;


        /*Breath-first search based loop traversal*/
        record_queue.emplace(root); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            int record_max_val = INT_MIN; //Record maximun value

            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                TreeNode * record_root = record_queue.front(); record_queue.pop(); //Keep updating, popped

                record_max_val = ((record_root->val) > record_max_val) ? (record_root->val) : record_max_val; //Keep updating, overwriting

                ///// Check if the next root left-half node existed or not /////
                if ((record_root->left) != nullptr) { record_queue.emplace((record_root->left)); } //Keep updating, recording
                else { ; }

                ///// Check if the next root right-half node existed or not /////
                if ((record_root->right) != nullptr) { record_queue.emplace((record_root->right)); } //Keep updating, recording
                else { ; }

            } //Queue-size

            res_vect.emplace_back(record_max_val); //Keep updating, recording
             
        } //Cycled-times

        return res_vect;
    }
};
