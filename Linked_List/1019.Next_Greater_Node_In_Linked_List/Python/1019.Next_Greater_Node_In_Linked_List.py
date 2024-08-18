# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def nextLargerNodes(self, head):
        """
        :type head: ListNode
        :rtype: List[int]
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Record stack array #####
        record_stack = []

        ##### Record indexes #####
        record_idx = 0

        ##### Result array #####
        res_arry = []


        ######################################################
        #Stack-based loop traversal with recorded stack array
        while (head):
            while (record_stack and ((record_stack[(-1)])[0] < (head.val))):
                [curr_val, curr_idx] = record_stack.pop() #Keep popping from back

                res_arry[curr_idx] = (head.val) #Keep updating/overwriting

            res_arry.append(0) #Keep updating/recording
            record_stack.append([(head.val), record_idx]) #Keep updating/recording

            head = (head.next) #Keep updating/overwriting

            record_idx += 1 #Keep updating/accumulating

        return res_arry
