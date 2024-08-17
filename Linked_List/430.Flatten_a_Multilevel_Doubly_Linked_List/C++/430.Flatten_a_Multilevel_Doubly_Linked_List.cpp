/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node * flatten(Node * head) 
    {
        //===============================//
        // Input type:                   //
        //   - Node * (head node)        //
        // Return type:                  //
        //   - Node * (result head node) //
        //===============================//
        if (! head) { return NULL; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Result vector /////
        vector<Node * > res_vect;

        ///// Length of result vector /////
        int len_res_vect;

        ///// Previous node /////
        Node * prev_node = NULL;


        /*Recursion-based DFS loop traversal*/
        ///// Step 1: Recursion function call (i.e. head node) /////
        dfs_traversal(head, res_vect);

        ///// Step 2: Post-process, final completions /////
        len_res_vect = res_vect.size(); //Length of result vector
        (len_res_vect--); //Update, Reduce

        for (int res_vect_idx = 0; (res_vect_idx < len_res_vect); (res_vect_idx++)) //Whole
        {
            ((res_vect[res_vect_idx])->next) = (res_vect[(res_vect_idx + 1)]); //Keep updating, overwriting
            ((res_vect[res_vect_idx])->prev) = prev_node; //Keep updating, overwriting
            ((res_vect[res_vect_idx])->child) = NULL; //Keep updating, overwriting

            prev_node = res_vect[res_vect_idx]; //Keep updating, overwriting

        } //Whole

        ((res_vect[len_res_vect])->next) = NULL; //Keep updating, overwriting
        ((res_vect[len_res_vect])->prev) = prev_node; //Keep updating, overwriting
        ((res_vect[len_res_vect])->child) = NULL; //Keep updating, overwriting

        return res_vect[0];
    }


    void dfs_traversal(Node * head, vector<Node * > & res_vect)
    {
        //==========================================//
        // Input type:                              //
        //   - Node * (head node)                   //
        //   - vector<Node * > ref. (result vector) //
        // Return type:                             //
        //   - void (no return)                     //
        //==========================================//
        if (! head) { return; } //Issue, Boundary-case handling

        res_vect.push_back(head); //Update, Record

        /*Whole process, flow*/
        dfs_traversal((head->child), res_vect); //Recursion function call (i.e. child node)
        dfs_traversal((head->next), res_vect); //Recursion function call (i.e. child node)
    }
};
