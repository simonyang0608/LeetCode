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
    ListNode * insertionSortList(ListNode * head) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (list-node head)        //
        // Return type:                           //
        //   - ListNode * (result list-node head) //
        //========================================//

        /*Initialize*/
        ///// Record, Sorted list-node head /////
        ListNode * record_head, * sorted_head;

        ///// Result list-node head /////
        ListNode * res_head = new ListNode((-5001));
        (res_head->next) = head;


        /*In-place pointer based loop traversal*/
        while (head && (head->next)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (((head->next)->val) >= (head->val))
            {
                head = (head->next); //Keep updating, overwriting
            }

            else
            {
                record_head = (head->next); //Record list-node head
                (head->next) = ((head->next)->next); //Keep updating, overwriting

                sorted_head = res_head; //Sorted list-node head

                while ((sorted_head->next) && ((sorted_head->next)->val) < (record_head->val)) //Part
                {
                    sorted_head = (sorted_head->next); //Keep updating, overwriting

                } //Part

                (record_head->next) = (sorted_head->next); //Keep updating, overwriting
                (sorted_head->next) = record_head; //Keep updating, overwriting
            }

        } //Whole

        return (res_head->next);
    }
};
