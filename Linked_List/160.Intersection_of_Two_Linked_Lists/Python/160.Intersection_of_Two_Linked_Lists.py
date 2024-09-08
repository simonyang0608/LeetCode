# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        #=========================================#
        # In-place pointer based traversal method #
        #=========================================#
        if ((not headA) or (not headB)): #Issue/Boundary-case handling
            return None

        ############
        #Initialize
        ##### Result list-node head (i.e. A, B) #####
        res_headA, res_headB = headA, headB

        #######################################
        #In-place pointer based loop traversal
        while (res_headA != res_headB):

            ##### Check if the current in-place pointer matched conditions or not #####
            if (not res_headA):
                res_headA = headB #Keep updating/overwriting
            else:
                res_headA = res_headA.next #Keep updating/overwriting

            if (not res_headB):
                res_headB = headA #Keep updating/overwriting
            else:
                res_headB = res_headB.next #Keep updating/overwriting

        return res_headA
