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
    ListNode * mergeKLists(vector<ListNode * > & lists) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<ListNode * > ref. (lists vector) //
        // Return type:                                //
        //   - ListNode * (result list node head)      //
        //=============================================//

        /*Initialize*/
        ///// Sorted vector /////
        vector<int> sorted_vect;
        sorted_vect.push_back((-10001));

        ///// Length of sorted, lists vector /////
        int len_sorted_vect, len_lists = (lists.size());

        ///// Result, Dummy list node head /////
        ListNode * res_head, * dummy_head, * head = new ListNode((-10001));

        dummy_head = head;
        res_head = dummy_head;


        /*Step 1: Updated, Recorded vector by sorted list node values*/
        for (int lists_idx = 0; (lists_idx < len_lists); (lists_idx++)) //Whole
        {
            (head->next) = (lists[lists_idx]); //Connected for the next lists-indexed node

            while (head && (head->next)) //Whole
            {
                sorted_vect.push_back(((head->next)->val)); //Keep appending, recording

                head = (head->next); //Keep traversing

            } //Whole

        } //Whole

        (sort((sorted_vect.begin()), (sorted_vect.end()))); //Sorted operations
        len_sorted_vect = (sorted_vect.size()); //Length of sorted vector


        /*Step 2: Greedy-based loop traversal with sorted list node values vector*/
        for (int sorted_vect_idx = 1; (sorted_vect_idx < len_sorted_vect); (sorted_vect_idx++)) //Whole
        {
            ((dummy_head->next)->val) = (sorted_vect[sorted_vect_idx]); //Keep updating, overwriting

            dummy_head = (dummy_head->next); //Keep traversing

        } //Whole

        return (res_head->next);
    }
};
