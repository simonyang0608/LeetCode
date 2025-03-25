# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Result summary value #####
        res_sum_val = [0]

        ####################
        #Whole process/flow
        self.dfsTraversal(root, root.val, res_sum_val) #Recursion function call (i.e. whole root tree-node)

        return res_sum_val[0]


    def dfsTraversal(self, root, record_sum, res_sum_val):
        """
        :type root: Optional[TreeNode]
        :type record_sum: int
        :type res_sum_val: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling
            res_sum_val[0] += record_sum #Update/Accumulate

            return

        ####################
        #Whole process/flow
        if (root.left):
            self.dfsTraversal(root.left, ((10 * record_sum) + (root.left).val), res_sum_val) #Recursion function call (i.e. root left-half node)
        
        if (root.right):
            self.dfsTraversal(root.right, ((10 * record_sum) + (root.right).val), res_sum_val) #Recursion function call (i.e. root right-half node)
