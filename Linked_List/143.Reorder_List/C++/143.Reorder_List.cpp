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
    void reorderList(ListNode * head) 
    {
        //=================================//
        // Input type:                     //
        //   - ListNode * (head list-node) //
        // Return type:                    //
        //   - void (no return)            //
        //=================================//

        /*Initialize*/
        ///// List-node heads (i.e. slow, fast) /////
        ListNode * slow = nullptr, * fast = head;

        ///// List-node heads (i.e. reverse-previous, last) /////
        ListNode * reverse_prev = nullptr, * reverse_last = nullptr;


        /*Two-pointers based loop traversal*/
        ///// Step 1: Looped-traversal for searching for the middle position /////
        slow = fast; //Update, Overwrite

        while ((fast != nullptr) && ((fast->next) != nullptr)) //Half-middle
        {
            slow = (slow->next); //Keep updating, traversing

            fast = ((fast->next)->next); //Keep updating, traversing

        } //Half-middle

        ///// Step 2: Looped-traversal for reversing the post-part list /////
        reverse_last = (slow->next); (slow->next) = nullptr; //Update, Overwrite

        while (reverse_last != nullptr) //Whole
        {
            ListNode * reverse_next = (reverse_last->next); //Reverse-next list-node

            (reverse_last->next) = reverse_prev; //Keep updating, recording

            reverse_prev = reverse_last; //Keep updating, overwriting

            reverse_last = reverse_next; //Keep updating, overwriting

        } //Whole

        ///// Step 3: Looped-traversal for the remained-process, flow /////
        while (head != nullptr) //Whole
        {
            ///// Check if the reversed-part of list-node existed or not /////
            if (reverse_prev != nullptr)
            {
                ListNode * curr_prev = reverse_prev; //Current previous list-node

                reverse_prev = (reverse_prev->next); //Keep updating, traversing

                (curr_prev->next) = (head->next); //Keep updating, recording

                (head->next) = curr_prev; //Keep updating, recording

                head = (curr_prev->next); //Keep updating, overwriting
            }
            else { head = (head->next); } //Keep updating, traversing

        } //Whole
    }
};
