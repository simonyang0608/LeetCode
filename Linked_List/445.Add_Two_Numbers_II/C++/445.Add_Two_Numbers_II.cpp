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
        ///// Record reversed list-nodes (i.e. l1, l2) /////
        ListNode * record_rl1 = nullptr, * record_rl2 = nullptr;

        ///// Record carry factor, flag /////
        int record_carry = 0;

        ///// Result, Record summary list-nodes /////
        ListNode * res_lsum = nullptr, * record_lsum = new ListNode((-1));


        /*Inplace-pointers based loop traversal*/
        res_lsum = (record_lsum); //Update, Overwrite

        record_rl1 = reverseList(l1); record_rl2 = reverseList(l2); //Reversed operations

        while ((record_rl1 != nullptr) || (record_rl2 != nullptr)) //Whole
        {
            int record_sum_val = record_carry; //Record summary value;

            ///// Check if the current list-node (i.e. l1) existed or not /////
            if (record_rl1 != nullptr) { record_sum_val += (record_rl1->val); record_rl1 = (record_rl1->next); } //Keep updating, traversing
            else { ; }

            ///// Check if the current list-node (i.e. l2) existed or not /////
            if (record_rl2 != nullptr) { record_sum_val += (record_rl2->val); record_rl2 = (record_rl2->next); } //Keep updating, traversing
            else { ; }

            ///// Check if the current summary value matched conditions or not /////
            if ((record_sum_val / 10)) { record_carry |= 1; record_sum_val %= 10; } //Keep updating, overwriting
            else
            {
                ///// Check if the current carry-factor matched conditions or not /////
                if (record_carry) { record_carry &= 0; } //Keep updating, reset
                else { ; }
            }

            (record_lsum->next) = new ListNode(record_sum_val); //Keep updating, recording

            record_lsum = (record_lsum->next); //Keep updating, traversing

        } //Whole

        ///// Check if the current carry-factor matched conditions or not /////
        if (record_carry) { (record_lsum->next) = new ListNode(record_carry); } //Keep updating, recording
        else { ; }

        return reverseList((res_lsum->next));
    }


    ListNode * reverseList(ListNode * lx)
    {
        //===================================//
        // Input type:                       //
        //   - ListNode * (lx list-node)     //
        // Return type:                      //
        //   - ListNode * (result list-node) //
        //===================================//

        /*Initialize*/
        ///// Record list-nodes (i.e. previous, next) /////
        ListNode * lprev = nullptr, * lnext = nullptr;

        /*Whole process, flow*/
        while (lx != nullptr) //Whole
        {
            lnext = (lx->next); //Keep Updating, overwriting

            (lx->next) = lprev; //Keep Updating, recording

            lprev = lx; //Keep Updating, overwriting

            lx = lnext; //Keep Updating, overwriting

        } //Whole

        return lprev;
    }
};
