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
    ListNode * mergeInBetween(ListNode * list1, int a, int b, ListNode * list2)
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (list1 list-node head)  //
        //   - int (a-th index)                   //
        //   - int (b-th index)                   //
        //   - ListNode * (list2 list-node head)  //
        // Return type:                           //
        //   - ListNode * (result list-node head) //
        //========================================//

        /*Initialize*/
        ///// List-nodes (i.e. record head, tail, result head) /////
        ListNode * record_head = nullptr, * record_tail = nullptr, * res_list1 = list1;

        ///// Record summary counter /////
        int record_cnter = 0;


        /*Inplace-pointers based loop traversal*/
        ///// Step 1: Looped-traversal for the list1 list-node head /////
        while (list1 != nullptr) //Whole
        {
            ///// Check if the current summary counter matched conditions or not /////
            if (record_cnter == (a - 1)) { record_head = list1; } //Keep updating, overwriting
            else if (record_cnter == b) { record_tail = list1; } //Keep updating, overwriting

            else { ; }

            (record_cnter++); //Keep updating, accumulating

            list1 = (list1->next); //Keep updating, traversing

        } //Whole

        ///// Step 2: Looped-traversal for the list2 list-node head /////
        (record_head->next) = list2; //Update, Overwrite

        while ((list2 != nullptr) && ((list2->next) != nullptr)) //Whole
        {
            list2 = (list2->next); //Keep updating, traversing

        } //Whole

        (list2->next) = (record_tail->next); //Update, Overwrite

        (record_tail->next) = nullptr; //Update, Overwrite

        return res_list1;
    }
};
