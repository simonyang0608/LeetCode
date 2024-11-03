# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sortedArrayToBST(self, nums):
        """
        :type nums: List[int]
        :rtype: Optional[TreeNode]
        """
        #==================================#
        # Recursion-based traversal method #
        #==================================#
        if (not nums): #Issue/Boundary-case handling
            return None

        ############
        #Initialize
        ##### Record middle index #####
        record_mid_idx = (len(nums) // 2)

        ################################
        #Recursion-based loop traversal
        root = TreeNode(nums[record_mid_idx]) #Root tree-node

        root.left = self.sortedArrayToBST(nums[: (record_mid_idx)]) #Recursion function call (i.e. root left-half tree-node)
        root.right = self.sortedArrayToBST(nums[(record_mid_idx + 1): ]) #Recursion function call (i.e. root right-half tree-node)

        return root
