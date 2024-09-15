# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#
        if (not head): #Issue/Boundary-case handling
            return None

        ############
        #Initialize
        ##### Record array #####
        record_arry = []

        ##### Record, Result list-node head #####
        res_head = record_head = ListNode((-101))


        #################################################
        #Greedy-based loop traversal with recorded array
        ##### Step 1: Record list-node value with array #####
        while (head):
            record_arry.append((head.val)) #Keep updating/recording

            head = (head.next) #Keep updating/overwriting

        len_record_arry = len(record_arry) #Length of record array
        record_terminal = (len_record_arry - (k % len_record_arry)) #Record terminal point

        ##### Step 2: Looped-traversal with recorded array #####
        for record_idx in range(record_terminal, len_record_arry):
            (record_head.next) = ListNode(record_arry[record_idx]) #Keep updating/overwriting

            record_head = (record_head.next) #Keep updating/overwriting

        for record_idx in range(record_terminal):
            (record_head.next) = ListNode(record_arry[record_idx]) #Keep updating/overwriting

            record_head = (record_head.next) #Keep updating/overwriting

        return (res_head.next)
