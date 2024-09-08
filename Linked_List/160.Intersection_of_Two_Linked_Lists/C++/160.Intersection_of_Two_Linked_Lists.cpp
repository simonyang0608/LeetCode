/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (list-node headA)       //
        //   - ListNode * (list-node headB)       //
        // Return type:                           //
        //   - ListNode * (result list-node head) //
        //========================================//
        if ((! headA) || (! headB)) { return NULL; }

        /*Initialize*/
        ///// Result list-node head (i.e. A, B) /////
        ListNode * res_headA = headA, * res_headB = headB;

        /*In-place pointer based loop traversal*/
        while (res_headA != res_headB) //Whole
        {
            ///// Check if the current list-node head matched conditions or not /////
            if (res_headA) { res_headA = res_headA->next; } //Keep updating, overwriting
            else { res_headA = headB; } //Keep updating, overwriting

            if (res_headB) { res_headB = res_headB->next; } //Keep updating, overwriting
            else { res_headB = headA; } //Keep updating, overwriting

        } //Whole

        return res_headA;
    }
};
