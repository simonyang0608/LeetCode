# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #==================================#
        # Recursion-based traversal method #
        #==================================#
        if ((not head) or (head and (not (head.next)))): #Issue/Boundary-case handling
            return head

        ################################
        #Recursion-based loop traversal
        new_head = (head.next) #Update/Overwrite

        (head.next) = self.swapPairs(((head.next).next)) #Recursion function call

        (new_head.next) = head #Update/Overwrite

        return new_head
