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
    ListNode * swapNodes(ListNode * head, int k) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (head list-node)        //
        //   - int (k-th index)                   //
        // Return type:                           //
        //   - ListNode * (result list-node head) //
        //========================================//

        /*Initialize*/
        ///// Record traversal window-size /////
        int record_trav_winsize = 1;

        ///// Record list-node head (i.e. previous, left, right) /////
        ListNode * record_prev_head, * record_left_head, * record_right_head = head;

        record_left_head = record_right_head;

        while (record_trav_winsize < k) //K-th index
        {
            (record_trav_winsize++);

            record_right_head = (record_right_head->next);

        } //K-th index

        record_prev_head = record_right_head;

        ///// Record temporal list-node value #####
        int record_tmp_val;


        /*Sliding-window based loop traversal*/
        while ((record_right_head->next)) //Rest
        {
            record_right_head = (record_right_head->next); //Keep updating, overwriting
            record_left_head = (record_left_head->next); //Keep updating, overwriting

        } //Rest

        record_tmp_val = (record_prev_head->val); //Temporal list-node value

        (record_prev_head->val) = (record_left_head->val); //Update, Overwrite & Swap
        (record_left_head->val) = record_tmp_val; //Update, Overwrite & Swap

        return head;
    }
};
