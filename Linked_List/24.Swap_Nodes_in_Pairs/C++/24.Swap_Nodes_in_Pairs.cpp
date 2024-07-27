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
    ListNode * swapPairs(ListNode * head) 
    {
        //==============================//
        // Input type:                  //
        //   - ListNode * (head node)   //
        // Return type:                 //
        //   - ListNode * (result node) //
        //==============================//
        if ((! head) || (head && (! (head->next)))) //Issue, Boundary-case handling
        {
            return head;
        }

        /*Recursion-based loop traversal*/
        ListNode * new_head = (head->next); //Update, Overwrite

        (head->next) = swapPairs(((head->next)->next)); //Recursion function call

        (new_head->next) = head; //Update, Overwrite

        return new_head;
    }
};
