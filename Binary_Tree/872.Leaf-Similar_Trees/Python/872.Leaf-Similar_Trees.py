# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def leafSimilar(self, root1, root2):
        """
        :type root1: Optional[TreeNode]
        :type root2: Optional[TreeNode]
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record arrays (i.e. 1, 2) #####
        record_arry1, record_arry2 = [], []

        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root1, record_arry1) #Recursion function call (i.e. whole root tree-node)
        self.dfsTraversal(root2, record_arry2) #Recursion function call (i.e. whole root tree-node)

        ##### Check if the current array is the same or not #####
        if (record_arry1 == record_arry2):
            return True

        return False

    
    def dfsTraversal(self, root, record_arry):
        """
        :type root: Optional[TreeNode]
        :type record_arry: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling
            record_arry.append(root.val) #Update/Record

            return

        self.dfsTraversal(root.left, record_arry) #Recursion function call (i.e. root left-half node)
        self.dfsTraversal(root.right, record_arry) #Recursion function call (i.e. root right-half node)
