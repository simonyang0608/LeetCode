# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Record summary counter #####
        record_cnter = 1

        ##### Record stack array #####
        record_stack = []

        ##### Result, Record list-node head #####
        res_head = record_head = ListNode((-501))


        ############################
        #Stack-based loop traversal
        ##### Step 1: Looped-traversal for the record list-node head (i.e. previous) #####
        while (head and (record_cnter < left)):
            (record_head.next) = ListNode((head.val)) #Keep updating/overwriting

            record_head = (record_head.next) #Keep updating/overwriting
            head = (head.next) #Keep updating/overwriting

            record_cnter += 1 #Keep updating/accumulating

        ##### Step 2: Looped-traversal for the middle list-node head with stack array #####
        while (head and (record_cnter <= right)):
            record_stack.append((head.val)) #Keep updating/recording

            head = (head.next) #Keep updating/overwriting

            record_cnter += 1 #Keep updating/accumulating

        ##### Step 3: Post-process/final completions #####
        while (record_stack):
            (record_head.next) = ListNode(record_stack.pop()) #Keep updating/overwriting

            record_head = (record_head.next) #Keep updating/overwriting

        (record_head.next) = head #Keep updating/overwriting

        return (res_head.next)
