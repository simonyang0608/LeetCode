# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        #==========================================#
        # In-place pointers based traversal method #
        #==========================================#

        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record summary counter #####
        record_cnter = 0

        ##### Record list-node head #####
        record_head = head


        #########################################################################
        #In-place pointers based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Looped-traversal with recorded dictionary/hashmap #####
        while (record_head):
            record_cnter += 1 #Keep updating/accumulating
            record_dict[record_cnter] = record_head #Keep updating/recording

            record_head = (record_head.next) #Keep updating/overwriting

        ##### Step 2: Post-process/completions #####
        removed_node_idx = (record_cnter - n) #List-node index to be removed

        record_dict[(record_cnter + 1)] = None #Update/Record

        ##### Check if the current list-node is None or not #####
        if (not removed_node_idx):
            return (head.next)

        (record_dict[removed_node_idx]).next = record_dict[(removed_node_idx + 2)] #Update/Overwrite

        return head
