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
        //====================================//
        // Input type:                        //
        //   - Node * (root tree-node)        //
        // Return type:                       //
        //   - Node * (result root tree-node) //
        //====================================//
        if (root == nullptr) { return nullptr; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record queue /////
        queue<Node * > record_queue;

        ///// Result vector /////
        vector<Node * > res_vect;

        
        /*Breath-first search based loop traversal with recorded queue*/
        record_queue.emplace(root); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            int queue_size = record_queue.size(); //Queue-size

            Node * first_node = record_queue.front(); record_queue.pop(); //First root tree-node

            res_vect.emplace_back(first_node); //Keep updating, recording

            ///// Check if the root left-half node existed or not /////
            if ((first_node->left) != nullptr) { record_queue.emplace((first_node->left)); } //Keep updating, recording
            else { ; }

            ///// Check if the root right-half node existed or not /////
            if ((first_node->right) != nullptr) { record_queue.emplace((first_node->right)); } //Keep updating, recording
            else { ; }

            for (int queue_idx = (queue_size - 1); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                Node * record_node = record_queue.front(); record_queue.pop(); //Record root tree-node

                ((res_vect.back())->next) = record_node; //Keep updating, overwriting

                res_vect.emplace_back(record_node); //Keep updating, recording

                ///// Check if the root left-half node existed or not /////
                if ((record_node->left) != nullptr) { record_queue.emplace((record_node->left)); } //Keep updating, recording
                else { ; }

                ///// Check if the root right-half node existed or not /////
                if ((record_node->right) != nullptr) { record_queue.emplace((record_node->right)); } //Keep updating, recording
                else { ; }

            } //Queue-size

        } //Cycled-times

        return res_vect.front();
    }
};
