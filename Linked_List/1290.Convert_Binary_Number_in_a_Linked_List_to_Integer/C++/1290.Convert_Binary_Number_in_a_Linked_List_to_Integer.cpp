/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        int resint = 0;
        while (head != NULL)
        {
            resint = (head->val+(resint)*2);
            head = head->next;
        }
        return resint;
    }
};
