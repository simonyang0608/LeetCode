# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapNodes(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Record traversal window-size #####
        record_trav_winsize = 1

        ##### Record list-node head (i.e. left/previous, right/after) #####
        record_left_head = record_right_head = head

        while (record_trav_winsize < k):
            record_trav_winsize += 1

            record_right_head = record_right_head.next

        record_prev_head = record_right_head


        #####################################
        #Sliding-window based loop traversal
        while (record_right_head.next):
            record_right_head = record_right_head.next #Keep updating/overwriting
            record_left_head = record_left_head.next #Keep updating/overwriting

        record_prev_head.val, record_left_head.val = record_left_head.val, record_prev_head.val #Update/Overwrite, Swap

        return head
