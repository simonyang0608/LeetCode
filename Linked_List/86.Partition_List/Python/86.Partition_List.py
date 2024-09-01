# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Result list-node head (i.e. prefix, suffix) #####
        res_prefix_head = prefix_head = ListNode((-101))
        res_suffix_head = suffix_head = ListNode((-101))

        #############################
        #Greedy-based loop traversal
        while (head):

            ##### Check if the current list-node value larger than target or not #####
            if ((head.val) < x):
                (prefix_head.next) = ListNode((head.val)) #Keep updating/overwriting

                prefix_head = (prefix_head.next) #Keep updating/overwriting

            else:
                (suffix_head.next) = ListNode((head.val)) #Keep updating/overwriting

                suffix_head = (suffix_head.next) #Keep updating/overwriting

            head = (head.next) #Keep updating/overwriting

        (prefix_head.next) = (res_suffix_head.next) #Update/Overwrite

        return (res_prefix_head.next)
