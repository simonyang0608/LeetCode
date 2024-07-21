# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def modifiedList(self, nums, head):
        """
        :type nums: List[int]
        :type head: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        #==========================================#
        # In-place pointers based traversal method #
        #==========================================#

        ############
        #Initialize
        ##### Set array updated #####
        nums = set(nums)

        ############################################################
        #In-place pointers based loop traversal with recorded array
        ##### Step 1: Remove matched list-nodes from front of head #####
        while (head and ((head.val) in nums)):
            head = (head.next) #Keep updating/overwriting

        res_head = head #Result head updated

        ##### Step 2: Post-processed traversals/completions #####
        while (head and (head.next)):

            ##### Check if the current list-node matched conditions or not #####
            if (((head.next).val) in nums):
                (head.next) = ((head.next).next) #Keep updating/overwriting
            else:
                head = (head.next) #Keep updating/overwriting

        return res_head
