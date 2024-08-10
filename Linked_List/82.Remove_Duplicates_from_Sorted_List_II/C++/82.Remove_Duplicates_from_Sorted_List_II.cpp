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
    ListNode * deleteDuplicates(ListNode * head) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (list-node head)        //
        // Return type:                           //
        //   - ListNode * (result list-node head) //
        //========================================//

        /*Initialize*/
        ///// Record hashmap, dictionary /////
        unordered_map<int, int> record_map;

        ///// Record list-node value /////
        int record_val;

        ///// Record, Result list-node head /////
        ListNode * res_head, * record_head = new ListNode((-101));
        (record_head->next) = head;

        res_head = record_head;


        /*In-place pointer based loop traversal with recorded hashmap, dictionary*/
        ///// Step 1: Record list-node value with hashmap, dictionary /////
        while (head) //Whole
        {
            record_val = (head->val); //Record list-node value

            ///// check if the current list-node value existed or not /////
            if (record_map.find(record_val) == record_map.end())
            {
                record_map[record_val] = 1; //Keep updating, recording
            }

            else { record_map[record_val] += 1; } //Keep updating, recording

            head = (head->next); //Keep updating, overwriting

        } //Whole

        ///// Step 2: Looped-traversal with recorded hashmap /////
        while (record_head && (record_head->next)) //Whole
        {
            ///// Check if the current list-node value is duplicate or not /////
            if (record_map[((record_head->next)->val)] > 1)
            {
                (record_head->next) = ((record_head->next)->next); //Keep updating, overwriting
            }

            else { record_head = (record_head->next); } //Keep updating, overwriting

        } //Whole

        return (res_head->next);
    }
};
