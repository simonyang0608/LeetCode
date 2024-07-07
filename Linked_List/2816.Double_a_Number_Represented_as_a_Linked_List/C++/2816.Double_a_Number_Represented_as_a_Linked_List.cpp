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
    ListNode * doubleIt(ListNode * head) 
    {
        //==============================//
        // Input type:                  //
        //   - ListNode * (head)        //
        // Return type:                 //
        //   - ListNode * (result head) //
        //==============================//

        /*Initialize*/
        ///// Current doubled represented list node value /////
        int curr_double_repr = ((head->val) << 1);

        ///// Result, Temporal head /////
        ListNode * res_head, * tmp_head;

        if (((curr_double_repr) / 10)) //Exceed decimal digits
        {
            tmp_head = new ListNode(1);
            res_head = tmp_head; //Pointer connection same

            (tmp_head->next) = new ListNode(((curr_double_repr) % 10)); //Quotient
            tmp_head = (tmp_head->next); //Keep traversing
        }
        else
        {
            tmp_head = new ListNode(((curr_double_repr) % 10)); //Quotient
            res_head = tmp_head; //Pointer connection same
        }


        /*One-pass greedy-based loop traversal*/
        while (head && (head->next)) //Whole
        {
            curr_double_repr = (((head->next)->val) << 1); //Current doubled represented list node value

            ///// Check if exceed decimal digits or not /////
            if (((curr_double_repr) / 10))
            {
                (tmp_head->val) += 1; //Keep accumulating
            }
            else { ; }
            
            (tmp_head->next) = new ListNode(((curr_double_repr) % 10));

            tmp_head = (tmp_head->next); //Keep traversing
            head = (head->next); //Keep traversing

        } //Whole

        return res_head;
    }
};
