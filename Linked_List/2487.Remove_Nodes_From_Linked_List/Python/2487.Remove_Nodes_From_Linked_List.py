# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Record stack #####
        record_stack = []

        ############################
        #Stack-based loop traversal
        while (head):
            while (record_stack and ((record_stack[(-1)]).val < head.val)):
                record_stack.pop() #Keep updating, popped

            ##### Check if the current stack matched conditions or not #####
            if (record_stack):
                (record_stack[(-1)]).next = head #Keep updating/recording
            else:
                pass

            record_stack.append(head) #Keep updating/recording

            head = head.next #Keep updating/traversing

        return record_stack[0]
