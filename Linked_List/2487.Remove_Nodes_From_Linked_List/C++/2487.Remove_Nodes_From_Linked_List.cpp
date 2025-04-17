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
    ListNode * removeNodes(ListNode * head) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (head list-node)        //
        // Return type:                           //
        //   - ListNode * (result head list-node) //
        //========================================//

        /*Initialize*/
        ///// Record vector /////
        vector<ListNode * > record_vect;

        /*Stack-based loop traversal*/
        while (head != nullptr) //Whole
        {
            while ((! record_vect.empty()) && (((record_vect.back())->val) < (head->val))) //Part
            {
                record_vect.pop_back(); //Keep updating, popped

            } //Part

            ///// Check if the current vector matched conditions or not /////
            if (! record_vect.empty()) { ((record_vect.back())->next) = head; } //Keep updating, recording
            else { ; }

            record_vect.emplace_back(head); //Keep updating, recording

            head = (head->next); //Keep updating, traversing

        } //Whole

        return record_vect.front();
    }
};
