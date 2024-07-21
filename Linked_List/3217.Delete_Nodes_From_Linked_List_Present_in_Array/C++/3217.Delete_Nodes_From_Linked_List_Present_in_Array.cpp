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
    ListNode * modifiedList(vector<int> & nums, ListNode * head) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - ListNode * (head)              //
        // Return type:                       //
        //   - ListNode * (result head)       //
        //====================================//

        /*Initialize*/
        ///// Set operations /////
        set<int> set_nums(nums.begin(), nums.end());

        ///// Result head /////
        ListNode * res_head;


        /*In-place pointers based loop traversal with recorded vector*/
        ///// Step 1: Remove matched list-nodes from front of head /////
        while (head && (set_nums.find((head->val)) != set_nums.end())) //Part
        {
            head = (head->next); //Keep updating, overwriting

        } //Part

        ///// Step 2: Post-processed traversals, completions /////
        res_head = head; //Result head updated

        while (head && (head->next)) //Whole
        {
            ///// Check if the current list-node matched conditions or not /////
            if (set_nums.find(((head->next)->val)) != set_nums.end())
            {
                (head->next) = ((head->next)->next); //Keep updating, overwriting
            }

            else { head = (head->next); } //Keep updating, overwriting

        } //Whole

        return res_head;
    }
};
