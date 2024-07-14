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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newnode = new ListNode(0);
        ListNode* answer = newnode;
        while (l1 and l2)
        {
            if (l1->val < l2->val)
            {
                newnode->next = l1;
                newnode = newnode->next;
                l1 = l1->next;
            }
            else
            {
                newnode->next = l2;
                newnode = newnode->next;
                l2 = l2->next;
            }
        }
        if (l1 != NULL & l2 == NULL)
        {
            newnode->next = l1;
        }
        else if (l2 != NULL & l1 == NULL)
        {
            newnode->next = l2;
        }
        else
        {
            newnode->next = NULL;
        }
        return answer->next;
    }
};
