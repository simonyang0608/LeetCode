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
    ListNode * oddEvenList(ListNode * head) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (head list-node)        //
        // Return type:                           //
        //   - ListNode * (result head list-node) //
        //========================================//
        if ((! head) || (! (head->next))) { return head; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Result, Current list-nodes (i.e. head, next-head) /////
        ListNode * res_next_head, * res_head = head, * next_head = (head->next);

        res_next_head = next_head;


        /*In-place pointer based loop traversal*/
        while (head && (head->next)) //Whole
        {
            (head->next) = ((head->next)->next); //Keep updating, overwriting

            ///// Check if the current list-node matched conditions or not /////
            if (next_head && ((next_head->next)))
            {
                (next_head->next) = ((next_head->next)->next); //Keep updating, overwriting

                head = (head->next); //Keep updating, overwriting
            }
            else { ; }

            next_head = (next_head->next); //Keep updating, overwriting
             
        } //Whole

        (head->next) = res_next_head; //Keep updating, overwriting

        return res_head;
    }
};
