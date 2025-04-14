# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def splitListToParts(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: List[Optional[ListNode]]
        """
        #==========================================#
        # In-place pointers based traversal method #
        #==========================================#

        ############
        #Initialize
        ##### Record head list-node #####
        record_head = head

        ##### Record quotient, module #####
        record_quot, record_module = (-1), (-1)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record summary counter #####
        record_cnter = 0

        ##### Result array #####
        res_arry = [None for _ in range(k)]


        ########################################
        #In-place pointers based loop traversal
        ##### Step 1: Looped-traversal for the length of list-node ##### 
        while (head):
            record_cnter += 1 #Keep updating/accumulating

            head = head.next #Keep updating/traversing

        ##### Step 2: Looped-traversal for the remainings #####
        record_quot, record_module = (record_cnter // k), (record_cnter % k) #Update/Overwrite

        while (record_head):
            curr_head = record_head #Current head list-node

            prev_head = None #Previous head list-node

            record_module -= 1 #Keep updating/reducing

            ##### Check if the current module matched conditions or not #####
            if (record_module >= 0):
                for record_idx in range((record_quot + 1), 0, (-1)):
                    prev_head = record_head #Keep updating/overwriting

                    record_head = record_head.next #Keep updating/traversing
            else:
                for record_idx in range(record_quot, 0, (-1)):
                    prev_head = record_head #Keep updating/overwriting

                    record_head = record_head.next #Keep updating/traversing

            prev_head.next = None #Keep updating/recording

            res_arry[record_trav_ptr] = curr_head #Keep updating/recording

            record_trav_ptr += 1 #Keep updating/traversing

        return res_arry
