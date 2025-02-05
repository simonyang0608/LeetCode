# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def constructMaximumBinaryTree(self, nums):
        """
        :type nums: List[int]
        :rtype: Optional[TreeNode]
        """
        #==============================#
        # Deque-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record deque #####
        record_dq = []


        ############################
        #Deque-based loop traversal
        for nums_idx in range(len_nums):
            record_node = TreeNode(nums[nums_idx]) #Record tree-node

            while (record_dq and ((record_dq[(-1)]).val < nums[nums_idx])):
                record_node.left = record_dq[(-1)] #Keep updating/overwriting

                record_dq.pop() #Keep updating/popped

            ##### Check if the current deque is empty or not #####
            if (record_dq):
                (record_dq[(-1)]).right = record_node #Keep updating/overwriting
            else:
                pass

            record_dq.append(record_node) #Keep updating/recording

        return record_dq[0]
