# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteMiddle(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #=========================================#
        # Inplace-pointers based traversal method #
        #=========================================#
        if ((not head) or ((not head.next))): #Issue/Boundary-case handling
            return None

        ############
        #Initialize
        ##### List-node heads (i.e. previous, slow, fast) #####
        prev_head = slow_head = fast_head = head

        #######################################
        #Inplace-pointers based loop traversal
        while (fast_head and fast_head.next):
            fast_head = (fast_head.next).next #Keep updating/traversing

            prev_head = slow_head #Keep updating/overwriting

            slow_head = slow_head.next #Keep updating/traversing

        prev_head.next = slow_head.next #Update/Overwrite

        slow_head.next = None #Update/Overwrite

        return head
