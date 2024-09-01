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
    ListNode * partition(ListNode * head, int x) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (list-node head)        //
        //   - int (x-target value)               //
        // Return type:                           //
        //   - ListNode * (result list-node head) //
        //========================================//

        /*Initialize*/
        ///// Result list-node head (i.e. prefix, suffix) /////
        ListNode * res_prefix_head, * prefix_head = new ListNode((-101));
        res_prefix_head = prefix_head;

        ListNode * res_suffix_head, * suffix_head = new ListNode((-101));
        res_suffix_head = suffix_head;


        /*Greedy-based loop traversal*/
        while (head) //Whole
        {
            ///// Check if the current list-node value larger than target or not /////
            if ((head->val) < x)
            {
                (prefix_head->next) = new ListNode((head->val)); //Keep updating, overwriting

                prefix_head = (prefix_head->next); //Keep updating, overwriting
            }

            else
            {
                (suffix_head->next) = new ListNode((head->val)); //Keep updating, overwriting

                suffix_head = (suffix_head->next); //Keep updating, overwriting
            }

            head = (head->next); //Keep updating, overwriting

        } //Whole

        (prefix_head->next) = (res_suffix_head->next); //Keep updating, overwriting

        return (res_prefix_head->next);
    }
};
