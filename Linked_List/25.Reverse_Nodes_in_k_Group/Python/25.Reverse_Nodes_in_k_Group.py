# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        #==================================#
        # Recursion-based traversal method #
        #==================================#
        if ((not head) or (not (head.next))): #Issue-Boundary-case handling
            return head

        ############
        #Initialize
        ##### Record index #####
        record_idx = 0

        ##### Record head #####
        record_head = head


        ################################
        #Recursion-based loop traversal
        ##### Step 1: Looped-traversal for 1-turns #####
        while (record_head and (record_idx < k)):
            record_head = (record_head.next) #Keep updating/overwriting

            record_idx += 1 #Keep updating/accumulating

        if (record_idx != k): #Issue/Boundary-case handling
            return head

        record_idx &= 0 #Update/Reset

        ##### Step 2: Looped-traversal for remained turns #####
        previous_head = head #Previous head initialize
        current_head = (previous_head.next) #Current head initialize

        while (record_idx < (k - 1)):
            next_head = (current_head.next) #Next head

            (current_head.next) = previous_head #Keep updating/overwriting

            previous_head = current_head #Keep updating/overwriting
            current_head = next_head #Keep updating/overwriting

            record_idx += 1 #Keep updating/accumulating

        (head.next) = self.reverseKGroup(record_head, k) #Recursion function call

        return previous_head
