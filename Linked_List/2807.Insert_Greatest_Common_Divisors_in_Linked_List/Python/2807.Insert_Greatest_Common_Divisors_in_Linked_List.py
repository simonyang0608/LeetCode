# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def insertGreatestCommonDivisors(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #==========================================#
        # In-place pointers based traversal method #
        #==========================================#

        ############
        #Initialize
        ##### Result head list-node #####
        res_head = head

        ########################################
        #In-place pointers based loop traversal
        while (head and head.next):
            head_next = head.next #Next head list-node

            gcd_head = ListNode(self.gcd(head.val, head_next.val)) #GCD head list-node

            gcd_head.next = head_next #Keep updating/recording

            head.next = gcd_head #Keep updating/recording

            head = head_next #Keep updating/overwriting

        return res_head

    
    def gcd(self, val1, val2):
        """
        :type val1: int
        :type val2: int
        :rtype: int
        """

        ############
        #Initialize
        ##### Record minimun value #####
        record_min_val = (val1 if (val1 < val2) else val2)

        ##### Result GCD value #####
        res_gcd = 1


        ####################
        #Whole process/flow
        record_min_val += 1 #Update/Accumulate

        for record_cd in range(1, record_min_val):

            ##### Check if the current CD matched conditions or not #####
            if ((not (val1 % record_cd)) and (not (val2 % record_cd))):
                res_gcd = record_cd #Keep updating/overwriting
            else:
                pass

        return res_gcd
