# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #===============================#
        # Recursion-based DFS traversal #
        #===============================#
        if (not root): #Issue/Boundary-case handling
            return 0

        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling
            return 1

        ####################################
        #Recursion-based DFS loop traversal
        left_height = self.maxDepth(root.left) #Recursion function call (i.e. root left-half node)
        right_height = self.maxDepth(root.right) #Recursion function call (i.e. root right-half node)

        return (max(left_height, right_height) + 1)
