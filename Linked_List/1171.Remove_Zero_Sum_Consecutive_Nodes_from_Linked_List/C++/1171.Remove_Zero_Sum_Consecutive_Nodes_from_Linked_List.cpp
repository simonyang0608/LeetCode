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
    ListNode * removeZeroSumSublists(ListNode * head) 
    {
        //===================================//
        // Input type:                       //
        //   - ListNode * (head list-node)   //
        // Return type:                      //
        //   - ListNode * (result list-node) //
        //===================================//

        /*Initialize*/
        ///// Prefix-summary value /////
        int prefix_sum = 0;

        ///// Record dictionary, hashmaap /////
        unordered_map<int, ListNode * > record_map;

        ///// Result, Record head list-node /////
        ListNode * res_head, * record_head = new ListNode(0, head);
        
        
        /*In-place pointers based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record prefix-summary order with dictionary, hashmap /////
        record_map[0] = new ListNode(0); //Update, Overwrite

        res_head = record_head; //Update, Overwrite

        while (head) //Whole
        {
            prefix_sum += (head->val); //Keep updating, accumulating

            ///// Check if the current prefix-summary value existed or not /////
            if (record_map.find(prefix_sum) != record_map.end())
            {
                ((record_map[prefix_sum])->next) = (head->next); //Keep updating, recording
            }
            else { record_map[prefix_sum] = head; ((record_map[(prefix_sum - (head->val))])->next) = record_map[prefix_sum]; } //Keep updating, recording

            head = (head->next); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        if (! prefix_sum) { return nullptr; } //Issue, Boundary-case handling

        prefix_sum &= 0; //Update, Reset

        while (record_head) //Whole
        {
            prefix_sum += (record_head->val); //Keep updating, accumulating

            (record_head->next) = ((record_map[prefix_sum])->next); //Keep updating, overwriting

            record_head = (record_head->next); //Keep updating, overwriting

        } //Whole

        return (res_head->next);
    }
};
