# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        #=========================================#
        # In-place pointer based traversal method #
        #=========================================#
        if ((not head) or (not (head.next))): #Issue/Boundary-case handling
            return head

        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record list-node head #####
        record_head = ListNode((-101))
        (record_head.next) = head

        ##### Result list-node head #####
        res_head = record_head


        ########################################################################
        #In-place pointer based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record list-node value with dictionary/hashmap #####
        while (head):
            record_val = (head.val) #Record list-node value

            ##### Check if the current list-node value existed or not #####
            if (record_val not in record_dict):
                record_dict[record_val] = 1 #Keep updating/recording
            else:
                record_dict[record_val] += 1 #Keep updating/recording

            head = (head.next) #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded dictionary #####
        while (record_head and (record_head.next)):

            ##### Check if the current list-node value is duplicate or not #####
            if (record_dict[((record_head.next).val)] > 1):
                (record_head.next) = ((record_head.next).next) #Keep updating/overwriting
            else:
                record_head = (record_head.next) #Keep updating/overwriting

        return (res_head.next)
