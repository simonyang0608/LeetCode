# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def removeLeafNodes(self, root, target):
        """
        :type root: TreeNode
        :type target: int
        :rtype: TreeNode
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        return self.dfsTraversal(root, target) #Recursion function call (i.e. root whole node)
        

    def dfsTraversal(self, root, target):
        """
        :type root: TreeNode
        :type target: int
        :rtype: TreeNode
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return None

        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling
            if (root.val == target):
                return None

            return root


        ####################
        #Whole process/flow
        root.left = self.dfsTraversal(root.left, target) #Recursion function call (i.e. root left-half node)
        root.right = self.dfsTraversal(root.right, target) #Recursion function call (i.e. root right-half node)

        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling
            if (root.val == target):
                return None

            return root

        return root
