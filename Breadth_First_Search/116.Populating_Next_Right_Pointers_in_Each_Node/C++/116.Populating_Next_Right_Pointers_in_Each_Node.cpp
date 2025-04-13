/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node * connect(Node * root) 
    {
        //===============================//
        // Input type:                   //
        //   - Node * (root tree-node)   //
        // Return type:                  //
        //   - Node * (result tree-node) //
        //===============================//
        if (root == nullptr) { return nullptr; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record queue /////
        queue<Node * > record_queue;

        ///// Result vector /////
        vector<Node * > res_vect;


        /*Breath-first search based loop traversal*/
        record_queue.emplace(root); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            bool is_start = false; //Is-start flag

            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                Node * record_root = record_queue.front(); record_queue.pop(); //Record root tree-node

                ///// Check if the current flag matched conditions or not /////
                if (! is_start) { res_vect.emplace_back(record_root); is_start |= true; } //Keep updating, recording
                else
                {
                    (res_vect.back())->next = record_root; //Keep updating, overwriting

                    res_vect.emplace_back(record_root); //Keep updating, recording
                }

                ///// Check if the root left-half node existed or not /////
                if ((record_root->left) != nullptr) { record_queue.emplace((record_root->left)); } //Keep updating, recording
                else { ; }

                ///// Check if the root right-half node existed or not /////
                if ((record_root->right) != nullptr) { record_queue.emplace((record_root->right)); } //Keep updating, recording
                else { ; }

            } //Queue-size

        } //Cycled-times

        return res_vect.front();
    }
};
