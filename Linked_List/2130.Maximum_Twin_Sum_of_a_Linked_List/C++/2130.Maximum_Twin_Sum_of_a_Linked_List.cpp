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
    int pairSum(ListNode * head) 
    {
        //=======================================//
        // Input type:                           //
        //   - ListNode * (head list-node)       //
        // Return type:                          //
        //   - int (result maximun twin-summary) //
        //=======================================//

        /*Initialize*/
        ///// Record pointers (i.e. slow, fast) /////
        ListNode * slow_ptr, * fast_ptr = head;
        slow_ptr = fast_ptr;

        ///// Record stack /////
        stack<int> record_stack;

        ///// Record twin-summary /////
        int record_twin_sum = 0;

        ///// Result maximun twin-summary /////
        int res_max_twin_sum = 0;


        /*Stack-based loop traversal with recorded pointers*/
        ///// Step 1: Record pointers value with stack /////
        while (fast_ptr && fast_ptr->next) //Previous-middle
        {
            record_stack.push(slow_ptr->val); //Keep updating, recording

            slow_ptr = slow_ptr->next; //Keep updating, overwriting
            fast_ptr = (fast_ptr->next)->next; //Keep updating, overwriting

        } //Previous-middle

        ///// Step 2: Looped-traversal with recorded stack /////
        while (slow_ptr) //Later-middle
        {
            record_twin_sum = (slow_ptr->val + record_stack.top()); //Record twin-summary

            record_stack.pop(); //Keep popped-last from stack

            res_max_twin_sum = (record_twin_sum > res_max_twin_sum) ? record_twin_sum : res_max_twin_sum; //Keep updating, overwriting

            slow_ptr = slow_ptr->next; //Keep updating, overwriting

        } //Later-middle

        return res_max_twin_sum;
    }
};
