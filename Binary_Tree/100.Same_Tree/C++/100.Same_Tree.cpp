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
    bool isSameTree(TreeNode * p, TreeNode * q) 
    {
        //===================================//
        // Input type:                       //
        //   - TreeNode * (p root tree-node) //
        //   - TreeNode * (q root tree-node) //
        // Return type:                      //
        //   - bool (result flag)            //
        //===================================//

        /*Initialize*/
        ///// Record queues (i.e. p, q) /////
        queue<TreeNode * > record_queue_p, record_queue_q;

        ///// Record blundary-value /////
        int record_bound_val = 1e5;


        /*Breath-first search based loop traversal*/
        record_queue_p.emplace(p); record_queue_q.emplace(q); //Update, Record

        while ((! record_queue_p.empty()) && (! record_queue_q.empty())) //Cycled-times
        {
            vector<int> record_vect_p, record_vect_q; //Record vectors (i.e. p, q)

            for (int queue_pidx = record_queue_p.size(); (queue_pidx > 0); (queue_pidx--)) //Queue-size (i.e. p)
            {
                TreeNode * record_root_p = record_queue_p.front(); record_queue_p.pop(); //Keep updating, popped

                ///// Check if the current root tree-node existed or not /////
                if (record_root_p == nullptr) { record_vect_p.emplace_back(record_bound_val); } //Keep updating, recording
                else
                {
                    record_vect_p.emplace_back((record_root_p->val)); //Keep updating, recording

                    record_queue_p.emplace((record_root_p->left)); //Keep updating, recording
                    record_queue_p.emplace((record_root_p->right)); //Keep updating, recording
                }

            } //Queue-size (i.e. p)

            for (int queue_qidx = record_queue_q.size(); (queue_qidx > 0); (queue_qidx--)) //Queue-size (i.e. q)
            {
                TreeNode * record_root_q = record_queue_q.front(); record_queue_q.pop(); //Keep updating, popped

                ///// Check if the current root tree-node existed or not /////
                if (record_root_q == nullptr) { record_vect_q.emplace_back(record_bound_val); } //Keep updating, recording
                else
                {
                    record_vect_q.emplace_back((record_root_q->val)); //Keep updating, recording

                    record_queue_q.emplace((record_root_q->left)); //Keep updating, recording
                    record_queue_q.emplace((record_root_q->right)); //Keep updating, recording
                }

            } //Queue-size (i.e. q)

            ///// Check if the current vectors matched conditions or not /////
            if (record_vect_p != record_vect_q) { return false; }

        } //Cycled-times

        return true;
    }
};
