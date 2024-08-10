# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #=========================================#
        # In-place pointer based traversal method #
        #=========================================#
        if ((not head) or (not (head.next))): #Issue/Boundary-case handling
            return head

        ############
        #Initialize
        ##### Result list-node head #####
        res_head = head

        #######################################
        #In-place pointer based loop traversal
        while (head and (head.next)):

            ##### Check if the current list-node value matched conditions or not #####
            if ((head.val) == ((head.next).val)):
                (head.next) = ((head.next).next) #Keep updating/overwriting
            else:
                head = (head.next) #Keep updating/overwriting

        return res_head
