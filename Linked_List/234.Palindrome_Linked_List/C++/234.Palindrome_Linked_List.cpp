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
    bool isPalindrome(ListNode * head) 
    {
        //=================================//
        // Input type:                     //
        //   - ListNode * (head list-node) //
        // Return type:                    //
        //   - bool (result flag)          //
        //=================================//
        if ((head->next) == nullptr) { return true; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record head list-nodes (i.e. slow, previous, fast) /////
        ListNode * slow = nullptr, * prev = nullptr, * fast = head;

        ///// Record head list-nodes (i.e. reversed-previous, last) ////
        ListNode * reverse_prev = nullptr, * reverse_last = nullptr;


        /*Two-pointers based loop traversal*/
        ///// Step 1: Looped-traversal for searching for the middle point /////
        slow = fast; //Update, Overwrite

        while ((fast != nullptr) && ((fast->next) != nullptr)) //Fast pointer
        {
            prev = slow; //Keep updating, overwriting

            slow = (slow->next); //Keep updating, traversing

            fast = ((fast->next)->next); //Keep updating, traversing

        } //Fast pointer

        ///// Step 2: Looped-traversal for reversing the post-part of list /////
        (prev->next) = nullptr; //Update, Record

        reverse_last = slow; //Update, Overwrite

        while (reverse_last != nullptr) //Whole
        {
            ListNode * reverse_next = (reverse_last->next); //Reversed-next list-node

            (reverse_last->next) = reverse_prev; //Keep updating, recording

            reverse_prev = reverse_last; //Keep updating, overwriting

            reverse_last = reverse_next; //Keep updating, overwriting

        } //Whole

        ///// Step 3: Looped-traversal for the remained list-nodes /////
        while ((reverse_prev != nullptr) && (head != nullptr)) //Whole intervals
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((reverse_prev->val) != (head->val)) { return false; }

            reverse_prev = (reverse_prev->next); //Keep updating, traversing

            head = (head->next); //Keep updating, traversing

        } //Whole intervals

        return true;
    }
};
