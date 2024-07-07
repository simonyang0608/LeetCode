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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = fast;
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
            {
                ListNode* detection = head;
                while (slow != detection)
                {
                    detection = detection->next;
                    slow = slow->next;
                }
                return detection;
            }
        }
        return NULL;
    }
};
