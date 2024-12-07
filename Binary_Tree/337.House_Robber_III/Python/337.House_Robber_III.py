# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rob(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        return max(self.dfsTraversal(root)) #Recursion function call (i.e. whole root node)
        

    def dfsTraversal(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return [0, 0]

        ####################
        #Whole process/flow
        left_arry = self.dfsTraversal(root.left) #Recursion function call (i.e. root left-half node)
        right_arry = self.dfsTraversal(root.right) #Recursion function call (i.e. root right-half node)

        return [(max(left_arry) + max(right_arry)), (root.val + left_arry[0] + right_arry[0])]
