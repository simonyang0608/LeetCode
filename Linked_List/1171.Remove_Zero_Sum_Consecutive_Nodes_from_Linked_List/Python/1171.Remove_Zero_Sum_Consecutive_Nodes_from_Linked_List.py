# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeZeroSumSublists(self, head):
        """
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #=========================================#
        # In-place pointer based traversal method #
        #=========================================#

        ############
        #Initialize
        ##### Prefix-summary value #####
        prefix_sum = 0

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result, Record list-node head #####
        res_head = record_head = ListNode(0, head)

        
        ########################################################################
        #In-place pointer based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record prefix-summary order with dictionary/hashmap #####
        record_dict[0] = ListNode(0) #Update/Overwrite

        while (head):
            prefix_sum += head.val #Keep updating/accumulating

            ##### Check if te current prefix-summary value existed or not #####
            if (prefix_sum in record_dict):
                (record_dict[prefix_sum]).next = head.next #Keep updating/overwriting
            else:
                record_dict[prefix_sum] = head #Keep updating/overwriting
                (record_dict[(prefix_sum - head.val)]).next = record_dict[prefix_sum] #Keep updating/overwriting

            head = head.next #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        if (not prefix_sum): #Issue/Boundary-case handling
            return None

        prefix_sum &= 0 #Update/Reset

        while (record_head):
            prefix_sum += record_head.val #Keep updating/accumulating

            record_head.next = (record_dict[prefix_sum]).next #Keep updating/overwriting

            record_head = record_head.next #Keep updating/overwriting

        return res_head.next
