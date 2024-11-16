# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def insertIntoBST(self, root, val):
        """
        :type root: Optional[TreeNode]
        :type val: int
        :rtype: Optional[TreeNode]
        """
        #==================================#
        # Recursion-based traversal method #
        #==================================#
        if (not root): #Issue/Boundary-case handling
            return TreeNode(val)

        ################################
        #Recursion-based loop traversal
        ##### Check if the current inserted-value matched conditions or not #####
        if ((root.val) >= val):
            root.left = self.insertIntoBST(root.left, val) #Recursion function call (i.e. root left-half node)
        else:
            root.right = self.insertIntoBST(root.right, val) #Recursion function call (i.e. root right-half node)

        return root
