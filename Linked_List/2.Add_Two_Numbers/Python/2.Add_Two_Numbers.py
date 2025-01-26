# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #========================================#
        # One-pass update based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Record list-node #####
        lrecord = ListNode((-1))

        ##### Record quotient #####
        record_quot = 0

        ##### Result list-node #####
        lres = lrecord


        ######################################
        #One-pass update based loop traversal
        while (l1 or l2):
            res_sum_val = record_quot #Result summary value

            ##### Check if the current list-node existed or not #####
            if (l1):
                res_sum_val += l1.val #Keep updating/accumulating

                l1 = l1.next #Keep updating/overwriting
            else:
                pass

            if (l2):
                res_sum_val += l2.val #Keep updating/accumulating

                l2 = l2.next #Keep updating/overwriting
            else:
                pass

            record_quot = (res_sum_val // 10) #Keep updating/overwriting
            record_mod = (res_sum_val % 10) #Record mod

            lrecord.next = ListNode(record_mod) #Keep updating/recording

            lrecord = lrecord.next #Keep updating/overwriting

        ##### Check if the current quotient matched conditions or not #####
        if (record_quot):
            lrecord.next = ListNode(record_quot) #Keep updating/recording
        else:
            pass

        return lres.next
