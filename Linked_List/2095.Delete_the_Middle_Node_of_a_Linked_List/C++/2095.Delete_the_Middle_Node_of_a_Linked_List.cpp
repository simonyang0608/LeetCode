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
    ListNode * deleteMiddle(ListNode * head) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (head list-node)        //
        // Return type:                           //
        //   - ListNode * (reault head list-node) //
        //========================================//
        if ((head == nullptr) || ((head->next) == nullptr)) { return nullptr; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// List-node heads (i.e. previous, slow, fast) /////
        ListNode * prev_head, * slow_head, * fast_head = head;

        slow_head = fast_head;


        /*Inplace-pointers based loop traversal*/
        while ((fast_head != nullptr) && ((fast_head->next) != nullptr)) //Fast-head
        {
            fast_head = ((fast_head->next)->next); //Keep updating, traversing

            prev_head = slow_head; //Keep updating, overwriting

            slow_head = (slow_head->next); //Keep updating, traversing

        } //Fast-head

        (prev_head->next) = (slow_head->next); //Update, Overwrite

        (slow_head->next) = nullptr; //Update, Overwrite

        return head;
    }
};
