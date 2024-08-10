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
    ListNode * deleteDuplicates(ListNode * head) 
    {
        //===================================//
        // Input type:                       //
        //   - ListNode * (head node)        //
        // Return type:                      //
        //   - ListNode * (result head node) //
        //===================================//
        if ((! head) || (! (head->next))) //Issue, Boundary-case handling
        {
            return head;
        }

        /*Initialize*/
        ///// Result head node /////
        ListNode * res_head = head;

        /*In-place pointer based loop traversal*/
        while (head && (head->next)) //Whole
        {
            ///// Check if the current list-node value matched conditions or not /////
            if ((head->val) == ((head->next)->val))
            {
                (head->next) = ((head->next)->next); //Keep updating, overwriting
            }

            else { head = (head->next); } //Keep updating, overwriting

        } //Whole

        return res_head;
    }
};
