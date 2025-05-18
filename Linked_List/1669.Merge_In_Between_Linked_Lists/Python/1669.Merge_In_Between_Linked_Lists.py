# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeInBetween(self, list1, a, b, list2):
        """
        :type list1: ListNode
        :type a: int
        :type b: int
        :type list2: ListNode
        :rtype: ListNode
        """
        #=========================================#
        # Inplace-pointers based traversal method #
        #=========================================#

        ############
        #Initialize
        ##### Record head list-nodes (i.e. record head, tail, result head) ######
        record_head, record_tail, res_list1 = None, None, list1

        ##### Record summary counter #####
        record_cnter = 0


        #######################################
        #Inplace-pointers based loop traversal
        ##### Step 1: Looped-traversal for the list1 list-node head #####
        while (list1):

            ##### Check if the current summary counter matched conditions or not #####
            if (record_cnter == (a - 1)):
                record_head = list1 #Keep updating/overwriting

            elif (record_cnter == b):
                record_tail = list1 #Keep updating/overwriting
            else:
                pass

            record_cnter += 1 #Keep updating/accumulating

            list1 = list1.next #Keep updating/traversing

        ##### Step 2: Looped-traversal for the list2 list-node head #####
        record_head.next = list2 #Update/Overwrite

        while (list2 and list2.next):
            list2 = list2.next #Keep updating/traversing

        list2.next = record_tail.next #Update/Overwrite

        record_tail.next = None #Update/Overwrite

        return res_list1
