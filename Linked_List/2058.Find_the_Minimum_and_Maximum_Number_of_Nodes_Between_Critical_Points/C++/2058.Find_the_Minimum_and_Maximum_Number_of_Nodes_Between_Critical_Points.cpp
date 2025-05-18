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
    vector<int> nodesBetweenCriticalPoints(ListNode * head) 
    {
        //=================================//
        // Input type:                     //
        //   - ListNode * (list-node head) //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// Previous head list-node /////
        ListNode * prev_head = head;

        ///// Record previous, initialized-index /////
        int prev_idx = (-1), record_init_idx = (-1);

        ///// Result minimun distance /////
        int res_min_dist = INT_MAX;

        ///// Record summary counter, index /////
        int record_cnter = 1;


        /*Greedy-based loop traversal*/
        head = (head->next); //Update, Traverse

        while ((head != nullptr) && ((head->next) != nullptr)) //Whole
        {
            int curr_val = (head->val); //Current list-node value

            ///// Check if the current list-node value matched conditions or not /////
            if ((((prev_head->val) < curr_val) && (((head->next)->val) < curr_val)) ||
                (((prev_head->val) > curr_val) && (((head->next)->val) > curr_val)))
            {
                ///// Check if the previous index matched conditions or not /////
                if (prev_idx == (-1)) { prev_idx = record_cnter; record_init_idx = prev_idx; } //Keep updating, overwriting
                else
                {
                    res_min_dist = min(res_min_dist, (record_cnter - prev_idx)); //Keep updating, overwriting

                    prev_idx = record_cnter; //Keep updating, overwriting
                }
            }
            else { ; }

            prev_head = head; //Keep updating, overwriting

            (record_cnter++); //Keep updating, accumulating

            head = (head->next); //Keep updating, traversing

        } //Whole

        ///// Check if the index value matched conditions or not /////
        if (prev_idx == (-1)) { return {(-1), (-1)}; }

        else if (prev_idx == record_init_idx) { return {(-1), (-1)}; }

        return {res_min_dist, (prev_idx - record_init_idx)};
    }
};
