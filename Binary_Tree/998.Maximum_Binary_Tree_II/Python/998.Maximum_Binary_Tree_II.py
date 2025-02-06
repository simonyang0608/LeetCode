# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def insertIntoMaxTree(self, root, val):
        """
        :type root: Optional[TreeNode]
        :type val: int
        :rtype: Optional[TreeNode]
        """
        #==================================#
        # Recursion-based traversal method #
        #==================================#

        return self.recurseTraversal(root, val)


    def recurseTraversal(self, root, val):
        """
        :type root: Optional[TreeNode]
        :type val: int
        :rtype: Optional[TreeNode]
        """
        #====================================#
        # Recursion-based traversal function #
        #====================================#
        if (root and (root.val > val)): #Issue/Boundary-case handling
            root.right = self.recurseTraversal(root.right, val) #Recursion function call (root right-half node)

            return root

        return TreeNode(val, root)
