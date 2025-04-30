# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (not root): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Result minimun depth #####
        res_min_depth = [((10 ** 5) + 1)]

        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, 1, res_min_depth) #Recursion function call (i.e. whole root tree-node)

        return res_min_depth[0]


    def dfsTraversal(self, root, record_depth, res_min_depth):
        """
        :type root: Optional[TreeNode]
        :type record_depth: int
        :type res_min_depth: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        ##### Check if the current root matched conditions or not #####
        if ((not root.left) and (not root.right)):

            ##### Check if the current indexed-value matched conditions or not #####
            if (record_depth < res_min_depth[0]):
                res_min_depth[0] = record_depth #Update/Overwrite

            return

        self.dfsTraversal(root.left, (record_depth + 1), res_min_depth) #Recursion function call (i.e. root left-half node)
        self.dfsTraversal(root.right, (record_depth + 1), res_min_depth) #Recursion function call (i.e. root right-half node)
