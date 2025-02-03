# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sufficientSubset(self, root, limit):
        """
        :type root: Optional[TreeNode]
        :type limit: int
        :rtype: Optional[TreeNode]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        return self.dfsTraversal(root, root.val, limit) #Recursion function call (i.e. whole root tree-node)


    def dfsTraversal(self, root, record_val, limit):
        """
        :type root: Optional[TreeNode]
        :type record_val: int
        :type limit: int
        :rtype: Optional[TreeNode]
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling

            ##### Check if the current value matched conditions or not #####
            if (record_val < limit):
                return None

            return root


        ##### Check if the next root tree-node is null or not #####
        if (root.left):
            root.left = self.dfsTraversal(root.left, (record_val + (root.left).val), limit) #Recursion function call (i.e. root left-half node)

        if (root.right):
            root.right = self.dfsTraversal(root.right, (record_val + (root.right).val), limit) #Recursion function call (i.e. root right-half node)

        if ((not root.left) and (not root.right)):
            return None

        return root
