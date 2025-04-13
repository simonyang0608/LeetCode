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
    ListNode * mergeNodes(ListNode * head) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (head list-node)        //
        // Return type:                           //
        //   - ListNode * (result head list-node) //
        //========================================//

        /*Initialize*/
        ///// Record head list-node /////
        ListNode * record_head = nullptr;

        ///// Result head list-node /////
        ListNode * res_head = nullptr;


        /*Greedy-based loop traversal*/
        while (head != nullptr) //Whole
        {
            int record_sum_val = 0; //Record summary value

            while (((head->next) != nullptr) && ((head->next)->val)) //Part
            {
                record_sum_val += ((head->next)->val); //Keep updating, accumulating

                head = (head->next); //Keep updating, overwriting

            } //Part

            ///// Check if the current summary value matched conditions or not /////
            if (record_sum_val)
            {
                ///// Check if the current list-node head matched conditions or not /////
                if (record_head == nullptr)
                {
                    record_head = new ListNode(record_sum_val); //Keep updating, recording

                    res_head = record_head; //Keep updating, overwriting
                }
                else
                {
                    (record_head->next) = new ListNode(record_sum_val); //Keep updating, recording

                    record_head = (record_head->next); //Keep updating, overwriting
                }
            }
            else { ; }

            head = (head->next); //Keep updating, overwriting

        } //Whole

        return res_head;
    }
};
