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
    ListNode * addTwoNumbers(ListNode * l1, ListNode * l2) 
    {
        //===================================//
        // Input type:                       //
        //   - ListNode * (l1 list-node)     //
        //   - ListNode * (l2 list-node)     //
        // Return type:                      //
        //   - ListNode * (result list-node) //
        //===================================//

        /*Initialize*/
        ///// Result, Record list-nodes /////
        ListNode * lres, * lrecord = new ListNode((-1));

        ///// Record quotient /////
        int record_quot = 0;


        /*One-pass update based loop traversal*/
        lres = lrecord; //Update, Overwrite

        while ((l1 != nullptr) || (l2 != nullptr)) //Whole
        {
            int record_sum_val = record_quot; //Record summary value

            ///// Check if the current list-node existed or not /////
            if (l1 != nullptr) { record_sum_val += (l1->val); l1 = (l1->next); } //Keep updating, overwriting
            else { ; }

            if (l2 != nullptr) { record_sum_val += (l2->val); l2 = (l2->next); } //Keep updating, overwriting
            else { ; }

            record_quot = (record_sum_val / 10); //Keep updating, overwriting

            int record_mod = (record_sum_val % 10); //Record mod

            (lrecord->next) = new ListNode(record_mod); //Keep updating, recording

            lrecord = (lrecord->next); //Keep updating, overwriting

        } //Whole

        ///// Check if the current quotient matched conditions or not /////
        if (record_quot) { (lrecord->next) = new ListNode(record_quot); } //Keep updating, recording
        else { ; }

        return (lres->next);
    }
};
