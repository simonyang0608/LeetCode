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
    vector<int> nextLargerNodes(ListNode * head) 
    {
        //=================================//
        // Input type:                     //
        //   - ListNode * (head node)      //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// Record stack /////
        stack<pair<int, int>> record_stack;

        ///// Record pairs /////
        pair<int, int> record_pair;

        ///// Record indexes /////
        int record_idx = 0;

        ///// Result vector /////
        vector<int> res_vect;


        /*Stack-based loop traversal*/
        while (head) //Whole
        {
            while ((! record_stack.empty()) && (((record_stack.top()).first) < (head->val))) //Part
            {
                record_pair = record_stack.top(); //Record pairs

                record_stack.pop(); //Keep popping from top

                res_vect[(record_pair.second)] = (head->val); //Keep updating, overwriting

            } //Part

            res_vect.push_back(0); //Keep updating, recording

            record_stack.push(make_pair((head->val), (record_idx++))); //Keep updating, recording

            head = (head->next); //Keep updating, recording

        } //Whole

        return res_vect;
    }
};
