/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode * rotateRight(ListNode * head, int k) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (list-node head)        //
        //   - int (k-th places)                  //
        // Return type:                           //
        //   - ListNode * (result list-node head) //
        //========================================//
        if (! head) { return NULL; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record vector /////
        vector<int> record_vect;

        ///// Length of record vector /////
        int len_record_vect;

        ///// Record terminal point /////
        int record_terminal;

        ///// Result, Record list-node head /////
        ListNode * res_head, * record_head = new ListNode((-101));
        res_head = record_head;


        /*Greedy-based loop traversal with recorded vector*/
        ///// Step 1: Record list-node value with vector /////
        while (head) //Whole
        {
            record_vect.push_back((head->val)); //Keep updating, overwriting

            head = (head->next); //Keep updating, overwriting

        } //Whole

        len_record_vect = record_vect.size(); //Length of record vector
        record_terminal = (len_record_vect - (k % len_record_vect));

        ///// Step 2: Looped-traversal with recorded vector /////
        for (int record_idx = record_terminal; (record_idx < len_record_vect); (record_idx++)) //Suffix
        {
            (record_head->next) = new ListNode(record_vect[record_idx]); //Keep updating, overwriting

            record_head = (record_head->next); //Keep updating, overwriting

        } //Suffix

        for (int record_idx = 0; (record_idx < record_terminal); (record_idx++)) //Preffix
        {
            (record_head->next) = new ListNode(record_vect[record_idx]); //Keep updating, overwriting

            record_head = (record_head->next); //Keep updating, overwriting

        } //Preffix

        return (res_head->next);
    }
};
