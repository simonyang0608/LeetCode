# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def maxPathSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Result maximun path #####
        res_max_path = [(((-3) * (10 ** 7)) - 1)]

        ####################################
        #Recursion-based DFS loop traversal
        record_max_path = self.dfsTraversal(root, res_max_path) #Recursion function call (i.e. whole root node)

        return res_max_path[0]


    def dfsTraversal(self, root, res_max_path):
        """
        :type root: Optional[TreeNode]
        :type res_max_path: int
        :rtype: int
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return 0

        ####################
        #Whole process/flow
        root_left_path = self.dfsTraversal(root.left, res_max_path) #Recursion function call (i.e. root left-half node)
        root_right_path = self.dfsTraversal(root.right, res_max_path) #Recursion function call (i.e. root right-half node)

        res_max_path[0] = max(res_max_path[0], root.val, (root.val + root_left_path), (root.val + root_right_path), (root.val + root_left_path + root_right_path)) #Update/Overwrite

        return max(root.val, (root.val + max(root_left_path, root_right_path)))
