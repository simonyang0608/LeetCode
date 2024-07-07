# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Previous node #####
        prev_node = None

        #############################
        #Greedy-based loop traversal
        while (head):
            next_node = (head.next) #Next node

            (head.next) = prev_node #Current head pointer reversed
            prev_node = head #Current stage

            head = next_node #Next stage 

        return prev_node
