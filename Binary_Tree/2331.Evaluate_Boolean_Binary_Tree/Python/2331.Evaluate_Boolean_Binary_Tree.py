# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def evaluateTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ####################################
        #Recursion-based DFS loop traversal
        res_bool = self.dfsTraversal(root) #Recursion function call (i.e. whole root node)

        return res_bool


    def dfsTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if ((not (root.left)) and (not (root.right))): #Issue/Boundary-case handling
            return (root.val)

        ####################
        #Whole process/flow
        ##### Step 1: Recursion-based DFS loop traversal #####
        root_left = self.dfsTraversal((root.left)) #Recursion function call (i.e. root left-half node)
        root_right = self.dfsTraversal((root.right)) #Recursion function call (i.e. root right-half node)

        ##### Check if the current root left/right-half node matched conditions or not #####
        if ((root.val) == 2): #Root node (i.e. or)
            return (root_left | root_right)

        if ((root.val) == 3): #Root node (i.e. and)
            return (root_left & root_right)
