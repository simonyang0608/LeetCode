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
    ListNode * reverseList(ListNode * head) 
    {
        //==============================//
        // Input type:                  //
        //   - ListNode * (head)        //
        // Return type:                 //
        //   - ListNode * (result head) //
        //==============================//

        /*Initialize*/
        ///// Next, Previous node /////
        ListNode * next_node, * prev_node = NULL;

        /*Greedy-based loop traversal*/
        while (head) //Whole
        {
            next_node = (head->next); //Next linked-list node

            (head->next) = prev_node; //Current linked-list pointer reversed
            prev_node = head; //Current stage

            head = next_node; //Next stage

        } //Whole

        return prev_node;
    }
};
