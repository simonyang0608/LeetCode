# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def doubleIt(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Result head #####
        if (((head.val) << 1) >= 10):
            res_head = tmp_head = (ListNode(1))
            (tmp_head.next) = (ListNode((((head.val) << 1) % 10)))
            tmp_head = (tmp_head.next)
        else:
            res_head = tmp_head = (ListNode((((head.val) << 1) % 10)))

        #############################
        #Greedy-based loop traversal
        while ((head and (head.next))):
            double_repr = (((head.next).val) << 1) #Doubled-represent list node value
            (tmp_head.next) = (ListNode((double_repr % 10))) #Start from the next list node traversal

            ##### Check if head next value carry or not #####
            if ((double_repr >= 10)):
                (tmp_head.val) += 1 #Carry
            else:
                pass

            head = (head.next) #Keep traversing
            tmp_head = (tmp_head.next) #Keep traversing

        return res_head
