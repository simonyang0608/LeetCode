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
    ListNode * reverseKGroup(ListNode * head, int k) 
    {
        //==============================//
        // Input type:                  //
        //   - ListNode * (head node)   //
        //   - int (k-th length)        //
        // Return type:                 //
        //   - ListNode * (result node) //
        //==============================//
        if ((! head) || (! (head->next))) //Issue, Boundary-case handling
        {
            return head;
        }

        /*Initialize*/
        ///// Previous, Current, Next, Record head /////
        ListNode * prev_head, * curr_head, * next_head, * record_head = head;

        ///// Record indexes /////
        int record_idx = 0;


        /*Recursion-based loop traversal*/
        ///// Step 1: Looped-traversal for the 1st-turns /////
        while (record_head && (record_idx < k)) //First-part
        {
            record_head = (record_head->next); //Keep updating, overwriting

            (record_idx++); //Keep updating, accumulating

        } //First-part

        if (record_idx < k) { return head; } //Issue, Boundary-case handling

        record_idx &= 0; //Update, Reset

        ///// Step 2: Looped-traversal for the remained-turns /////
        prev_head = head; //Previous head initialize
        curr_head = (prev_head->next); //Current head initialize

        while (record_idx < (k - 1)) //Remained-part
        {
            next_head = (curr_head->next); //Keep updating, overwriting

            (curr_head->next) = prev_head; //Keep updating, overwriting

            prev_head = curr_head; //Keep updating, overwriting
            curr_head = next_head; //Keep updating, overwriting

            (record_idx++); //Keep updating, accumulating

        } //Remained-part

        (head->next) = reverseKGroup(record_head, k); //Recursion function call

        return prev_head;
    }
};
