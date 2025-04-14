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
    vector<ListNode *> splitListToParts(ListNode * head, int k) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (head list-node)        //
        //   - int (k-th counter)                 //
        // Return type:                           //
        //   - vector<ListNode *> (result vector) //
        //========================================//

        /*Initialize*/
        ///// Record head list-node /////
        ListNode * record_head = head;

        ///// Record quotient, module /////
        int record_quot = (-1), record_module = (-1);

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Result vector /////
        vector<ListNode * > res_vect(k, nullptr);


        /*In-place pointers based loop traversal*/
        ///// Step 1: Looped-traversal for the length of list-node /////
        while (head != nullptr) //Whole
        {
            (record_cnter++); //Keep updating, accumulating

            head = (head->next); //Keep updating, traversing
        }

        ///// Step 2: Looped-traversal for the remainings /////
        record_quot = (record_cnter / k); record_module = (record_cnter % k); //Update, Overwrite

        while (record_head != nullptr) //Whole
        {
            ListNode * curr_head = record_head; //Current head list-node

            ListNode * prev_head = nullptr; //Previous head list-node

            ///// Check if the current module counter matched conditions or not /////
            if ((--record_module) >= 0)
            {
                for (int record_idx = (record_quot + 1); (record_idx > 0); (record_idx--)) //Counter-times
                {
                    prev_head = record_head; //Keep updating, overwriting

                    record_head = (record_head->next); //Keep updating, traversing

                } //Counter-times
            }
            else
            {
                for (int record_idx = record_quot; (record_idx > 0); (record_idx--)) //Counter-times
                {
                    prev_head = record_head; //Keep updating, overwriting

                    record_head = (record_head->next); //Keep updating, traversing

                } //Counter-times
            }

            (prev_head->next) = nullptr; //Keep updating, recording

            res_vect[(record_trav_ptr++)] = curr_head; //Keep updating, recording

        } //Whole

        return res_vect;
    }
};
