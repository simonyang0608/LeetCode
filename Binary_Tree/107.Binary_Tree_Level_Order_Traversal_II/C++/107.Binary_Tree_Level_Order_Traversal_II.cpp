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
    vector<vector<int>> levelOrderBottom(TreeNode * root) 
    {
        //=========================================//
        // Input type:                             //
        //   - TreeNode * (root tree-node)         //
        // Return type:                            //
        //   - vector<vector<int>> (result vector) //
        //=========================================//

        /*Initialize*/
        ///// Record queue /////
        queue<TreeNode * > record_queue;

        ///// Result vector /////
        vector<vector<int>> res_vect;


        /*Breath-first search based loop traversal*/
        if (root == nullptr) { return res_vect; } //Issue, Boundary-case handling

        record_queue.emplace(root); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            vector<int> record_vect; //Record vector

            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                TreeNode * record_root = record_queue.front(); record_queue.pop(); //Keep updating, popped

                record_vect.emplace_back((record_root->val)); //Keep updating, recording

                ///// Check if the root left-half node existed or not /////
                if ((record_root->left) != nullptr) { record_queue.emplace((record_root->left)); } //Keep updating, recording
                else { ; }

                ///// Check if the root right-half node existed or not /////
                if ((record_root->right) != nullptr) { record_queue.emplace((record_root->right)); } //Keep updating, recording
                else { ; }

            } //Queue-size

            res_vect.push_back(record_vect); //Keep updating, recording

        } //Cycled-times

        reverse(res_vect.begin(), res_vect.end()); //Reversed operations

        return res_vect;
    }
};
