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
    ListNode * reverseBetween(ListNode * head, int left, int right) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (list-node head)        //
        //   - int (left start point)             //
        //   - int (right end point)              //
        // Return type:                           //
        //   - ListNode * (result list-node head) //
        //========================================//

        /*Initialize*/
        ///// Record stack /////
        stack<int> record_stack;

        ///// Record summary counter /////
        int record_cnter = 1;

        ///// Result, Record list-node head /////
        ListNode * res_head, * record_head = new ListNode((-501));
        res_head = record_head;


        /*Stack-based loop traversal*/
        ///// Step 1: Looped-traversal for the previous list-node head /////
        while (head && (record_cnter < left)) //Previous
        {
            (record_head->next) = new ListNode((head->val)); //Keep updating, overwriting

            record_head = (record_head->next); //Keep updating, overwriting
            head = (head->next); //Keep updating, overwriting

            (record_cnter++); //Keep updating, accumulating

        } //Previous

        ///// Step 2: Looped-traversal for the middle list-node head /////
        while (head && (record_cnter <= right)) //Middle
        {
            record_stack.push((head->val)); //Keep updating, recording

            head = (head->next); //Keep updating, overwriting

            (record_cnter++); //Keep updating, accumulating

        } //Middle

        ///// Step 3: Post-process, final completions /////
        while (! (record_stack.empty())) //Whole
        {
            (record_head->next) = new ListNode(record_stack.top()); //Keep updating, overwriting

            record_stack.pop(); //Keep updating, popping

            record_head = (record_head->next); //Keep updating, overwriting

        } //Whole

        (record_head->next) = head; //Keep updating, overwriting

        return (res_head->next);
    }
};
