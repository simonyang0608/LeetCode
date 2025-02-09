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
    ListNode* sortList(ListNode* head) 
    {
        //========================================//
        // Input type:                            //
        //   - ListNode * (head list-node)        //
        // Return type:                           //
        //   - ListNode * (result head list-node) //
        //========================================//
        if ((head == nullptr) || ((head->next) == nullptr)) { return head; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Head list-node (i.e. previous, slow, fast) /////
        ListNode * prev_head, * slow_head, * fast_head = head;

        slow_head = fast_head; //Update, Overwrite


        /*Recursion-based merge sort loop traversal*/
        while ((fast_head != nullptr) && ((fast_head->next) != nullptr)) //Half
        {
            prev_head = slow_head; //Keep updating, overwriting

            slow_head = (slow_head->next); //Keep updating, traversing

            fast_head = ((fast_head->next)->next); //Keep updating, traversing

        } //Half

        (prev_head->next) = nullptr; //Keep updating, overwriting

        ListNode * left_head = sortList(head); //Recursion function call (i.e. head left-half list-node)
        ListNode * right_head = sortList(slow_head); //Recursion function call (i.e. head right-half list-node)

        return mergeSort(left_head, right_head);
    }


    ListNode * mergeSort(ListNode * left_head, ListNode * right_head)
    {
        //============================================//
        // Input type:                                //
        //   - ListNode * (head left-half list-node)  //
        //   - ListNode * (head right-half list-node) //
        // Return type:                               //
        //   - ListNode * (result head list-node)     //
        //============================================//

        /*Initialize*/
        ///// Head list-node (i.e. result, record) /////
        ListNode * res_head, * record_head = new ListNode(((-1) * 1e5) - 1);

        res_head = record_head; //Update, Overwrite


        /*Whole process, flow*/
        while ((left_head != nullptr) && (right_head != nullptr)) //Whole
        {
            ///// Check if the current node-value is smaller or not /////
            if ((left_head->val) < (right_head->val))
            {
                (record_head->next) = left_head; //Keep updating, overwriting

                left_head = (left_head->next); //Keep updating, traversing
            }
            else
            {
                (record_head->next) = right_head; //Keep updating, overwriting

                right_head = (right_head->next); //Keep updating, traversing
            }

            record_head = (record_head->next); //Keep updating, traversing

        } //Whole

        ///// Check if the remainings is left or right-half /////
        if (left_head != nullptr) { (record_head->next) = left_head; } //Keep updating, overwriting
        else { (record_head->next) = right_head; } //Keep updating, overwriting

        return (res_head->next);
    }
};
