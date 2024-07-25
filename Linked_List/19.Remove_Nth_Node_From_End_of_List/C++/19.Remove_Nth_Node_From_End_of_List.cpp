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
    ListNode * removeNthFromEnd(ListNode * head, int n) 
    {
        //===================================//
        // Input type:                       //
        //   - ListNode * (head node)        //
        //   - int (n-th index)              //
        // Return type:                      //
        //   - ListNode * (result head node) //
        //===================================//

        /*Initialize*/
        ///// Record hashmap, dictionary /////
        unordered_map<int, ListNode * > record_map;

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Record removed index /////
        int record_removed_idx;

        ///// Record list-node head /////
        ListNode * record_head = head;


        /*In-place pointers based loop traversal with recorded hashmap, dictionary*/
        ///// Step 1: Looped-traversal with recorded hashmap, dictionary /////
        while (record_head) //Whole
        {
            record_map[(++record_cnter)] = record_head; //Keep updating, overwriting

            record_head = (record_head->next); //Keep updating, overwriting

        } //Whole

        ///// Step 2: Final post-process, completions /////
        record_removed_idx = (record_cnter - n); //Record removed index

        record_map[(++record_cnter)] = NULL; //Update, Record

        ///// Check if the current removed index matched conditions or not /////
        if (! record_removed_idx) { return (head->next); }

        ((record_map[record_removed_idx])->next) = record_map[(record_removed_idx + 2)]; //Update, overwrite

        return head;
    }
};
