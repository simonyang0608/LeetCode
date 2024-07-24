# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Record summary values (i.e. l1, l2) #####
        record_sum_l1, record_sum_l2 = 0, 0

        ##### Record digits #####
        record_digit = 0

        ##### Result list-node #####
        lres = ltmp = ListNode((-1))


        ##########################################################
        #Greedy-based loop traversal with recorded summary values
        ##### Step 1: Record summary values with list-nodes (i.e. l1, l2) #####
        while (l1):
            record_sum_l1 += ((10 ** record_digit) * (l1.val)) #Keep updating/accumulating

            record_digit += 1 #Keep updating/accumulating

            l1 = (l1.next) #Keep updating/overwriting

        record_digit &= 0 #Update/Reset

        while (l2):
            record_sum_l2 += ((10 ** record_digit) * (l2.val)) #Keep updating/accumulating

            record_digit += 1 #Keep updating/accumulating

            l2 = (l2.next) #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded summary values #####
        res_str = ((str((record_sum_l1 + record_sum_l2)))[::(-1)]) #Keep updating/overwriting

        for res_char in res_str:
            (ltmp.next) = ListNode(int(res_char)) #Keep updating/newing

            ltmp = (ltmp.next) #Keep updating/overwriting

        return (lres.next)
