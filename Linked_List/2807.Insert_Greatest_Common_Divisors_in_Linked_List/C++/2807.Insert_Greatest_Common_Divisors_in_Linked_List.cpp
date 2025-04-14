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
    ListNode * insertGreatestCommonDivisors(ListNode * head) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (head list-node)        //
        // Return type:                           //
        //   - ListNode * (result head list-node) //
        //========================================//

        /*Initialize*/
        ///// Result head list-node /////
        ListNode * res_head = head;

        /*In-place pointers based loop traversal*/
        while ((head != nullptr) && ((head->next) != nullptr)) //Whole
        {
            ListNode * head_next = (head->next); //Next head list-node

            ListNode * head_gcd = new ListNode(__gcd((head->val), ((head->next)->val))); //GCD head list-node

            (head_gcd->next) = head_next; //Keep updating, recording

            (head->next) = head_gcd; //Keep updating, recording

            head = head_next; //Keep updating, overwriting

        } //Whole

        return res_head;
    }
};
