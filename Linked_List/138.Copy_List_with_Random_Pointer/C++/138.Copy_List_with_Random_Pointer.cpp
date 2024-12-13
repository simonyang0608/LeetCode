/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node * copyRandomList(Node * head) 
    {
        //====================================//
        // Input type:                        //
        //   - Node * (head list-node)        //
        // Return type:                       //
        //   - Node * (result head list-node) //
        //====================================//
        if (! head) { return NULL; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record dictionary, hashmap /////
        unordered_map<Node * , Node * > record_map;

        ///// Result, Record head list-node /////
        Node * res_head, * record_head = recurseTraversal(head, record_map);

        res_head = record_head;


        /*Recursion-based loop traversal with recorded dictionary, hasmap*/
        while (head) //Whole
        {
            ///// Check if the current random pointer existed or not /////
            if ((head->random))
            {
                (record_head->random) = record_map[(head->random)]; //Keep updating, overwriting
            }
            else { ; }

            head = (head->next); //Keep updating, overwriting
            record_head = (record_head->next); //Keep updating, overwriting

        } //Whole

        return res_head;
    }


    Node * recurseTraversal(Node * head, unordered_map<Node * , Node * > & record_map)
    {
        //=======================================================================//
        // Input type:                                                           //
        //   - Node * (head list-node)                                           //
        //   - unordered_map<Node * , Node * > ref. (record dictionary, hashmap) //
        // Return type:                                                          //
        //   - Node * (result head list-node)                                    //
        //=======================================================================// 
        if (! head) { return NULL; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        Node * res_head = new Node((head->val)); //Result list-node head

        (res_head->next) = recurseTraversal((head->next), record_map); //Update, Overwrite

        (res_head->random) = NULL; //Update, Overwrite

        record_map[head] = res_head; //Update, Record

        return res_head;
    }
};
