# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def searchBST(self, root, val):
        """
        :type root: Optional[TreeNode]
        :type val: int
        :rtype: Optional[TreeNode]
        """
        #==================================#
        # Recursion-based traversal method #
        #==================================#

        return self.recurseTraversal(root, val) #Recursion function call


    def recurseTraversal(self, root, val):
        """
        :type root: Optional[TreeNode]
        :type val: int
        :rtype: Optional[TreeNode]
        """
        #====================================#
        # Recursion-based traversal function #
        #====================================#
        if (not root): #Issue/Boundary-case handling
            return None

        if (root.val == val): #Issue/Boundary-case handling
            return root

        ####################
        #Whole process/flow
        ##### Check if the current tree-node value matched conditions or not #####
        if (val > root.val):
            return self.recurseTraversal(root.right, val) #Recursion function call (i.e. root right-half node)

        else:
            return self.recurseTraversal(root.left, val) #Recursion function call (i.e. root right-half node)
