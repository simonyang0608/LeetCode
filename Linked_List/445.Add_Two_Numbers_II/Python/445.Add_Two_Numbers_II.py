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
        #=========================================#
        # Inplace-pointers based traversal method #
        #=========================================#

        ############
        #Initialize
        ##### Record reversed list-nodes (i.e. l1, l2) #####
        record_rl1, record_rl2 = self.reverseList(l1), self.reverseList(l2)

        ##### Record carry #####
        record_carry = 0

        ##### Result, Record list-nodes #####
        res_lsum = record_lsum = ListNode((-1))


        #######################################
        #Inplace-pointers based loop traversal
        while (record_rl1 or record_rl2):
            record_sum_val = record_carry #Record summary value

            ##### Check if the current list-node (i.e. l1) existed or not #####
            if (record_rl1):
                record_sum_val += record_rl1.val #Keep updating/accumulating

                record_rl1 = record_rl1.next #Keep updating/traversing
            else:
                pass

            ##### Check if the current list-node (i.e. l2) existed or not #####
            if (record_rl2):
                record_sum_val += record_rl2.val #Keep updating/accumulating

                record_rl2 = record_rl2.next #Keep updating/traversing
            else:
                pass

            ##### Check if the current summary value matched conditions or not #####
            if ((record_sum_val // 10)):
                record_carry |= 1 #Keep updating/overwriting

                record_sum_val %= 10 #Keep updating/overwriting
            else:
                ##### Check if the current carry-factor matched conditions or not #####
                if (record_carry):
                    record_carry &= 0 #Keep updating/reset
                else:
                    pass

            record_lsum.next = ListNode(record_sum_val) #Keep updating/recording

            record_lsum = record_lsum.next #Keep updating/traversing

        ##### Check if the current carry-factor matched conditions or not #####
        if (record_carry):
            record_lsum.next = ListNode(record_carry) #Keep updating/recording
        else:
            pass

        return self.reverseList(res_lsum.next)


    def reverseList(self, lx):
        """
        :type lx: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        ############
        #Initialize
        ##### Record list-nodes (i.e. previous, next) #####
        lprev, lnext = None, None

        ####################
        #Whole process/flow
        while (lx):
            lnext = lx.next #Keep updating/overwriting

            lx.next = lprev #Keep updating/recording

            lprev = lx #Keep updating/overwriting

            lx = lnext #Keep updating/overwriting

        return lprev
