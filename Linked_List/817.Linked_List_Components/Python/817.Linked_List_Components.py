# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def numComponents(self, head, nums):
        """
        :type head: Optional[ListNode]
        :type nums: List[int]
        :rtype: int
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result summary counter #####
        res_cnter = 0


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Record indexed-value informations with dictionary/hashmap #####
        for nums_idx in range(len_nums):
            record_dict[nums[nums_idx]] = True #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        while (head):

            ##### Check if the current list-node value existed or not #####
            if (head.val not in record_dict):
                head = head.next #Keep updating/traversing

                continue

            res_cnter += 1 #Keep updating/accumulating

            while (head.next and ((head.next).val in record_dict)):
                head = head.next #Keep updating/traversing

            head = head.next #Keep updating/traversing

        return res_cnter
