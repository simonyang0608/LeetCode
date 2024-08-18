# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (not root): #Issue/Boundary-case handling
            return None

        if ((not (root.left)) and (not (root.right))): #Issue/Boundary-case handling
            return root


        ####################################
        #Recursion-based DFS loop traversal
        (root.left), (root.right) = self.invertTree((root.right)), self.invertTree((root.left)) #Recursion function call (i.e. root left, right-half node)

        return root
