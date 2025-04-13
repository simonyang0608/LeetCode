# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeNodes(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Result, Record head list-nodes #####
        res_head, record_head = None, None

        #############################
        #Greedy-based loop traversal
        while (head):
            record_sum_val = 0 #Record summary value

            while (head.next and (head.next).val):
                record_sum_val += (head.next).val #Keep updating/accumulating

                head = head.next #Keep updating/overwriting

            ##### Check if the current summary value matched conditions or not #####
            if (record_sum_val):

                ##### Check if the current head list-node matched conditions or not #####
                if (not record_head):
                    record_head = ListNode(record_sum_val) #Keep updating/recording

                    res_head = record_head #Keep updating/overwriting
                else:
                    record_head.next = ListNode(record_sum_val) #Keep updating/recording

                    record_head = record_head.next #Keep updating/overwriting
            else:
                pass

            head = head.next #Keep updating/overwriting

        return res_head
