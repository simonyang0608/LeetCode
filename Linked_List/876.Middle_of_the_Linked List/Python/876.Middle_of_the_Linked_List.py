# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def middleNode(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        slow = fast = ListNode(0)
        fast.next = head
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next
        return slow.next if fast else slow
