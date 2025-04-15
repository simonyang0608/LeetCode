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
    int numComponents(ListNode * head, vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - ListNode * (head list-node)    //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result summary counter)   //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, bool> record_map;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Hashmap-based loop traversal*/
        ///// Step 1: Record indexed-value informations with dictionary, hashmap /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_map[nums[nums_idx]] = true; //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        while (head != nullptr) //Whole
        {
            ///// Check if the current list-node value existed or not /////
            if (! record_map[(head->val)]) { head = (head->next); continue; }

            (res_cnter++); //Keep updating, accumulating

            while (((head->next) != nullptr) && record_map[((head->next)->val)]) //Part
            {
                head = (head->next); //Keep updating, traversing

            } //Part

            head = (head->next); //Keep updating, traversing

        } //Whole

        return res_cnter;
    }
};
