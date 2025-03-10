# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def goodNodes(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Result summary counter #####
        res_cnter = [0]

        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, (((-1) * (10 ** 4)) - 1), res_cnter) #Recursion function call (i.e. whole root tree-node)

        return res_cnter[0]

    
    def dfsTraversal(self, root, record_max_val, res_cnter):
        """
        :type root: TreeNode
        :type record_max_val: int
        :type res_cnter: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        ##### Check if the current value matched conditions or not #####
        if (root.val >= record_max_val):
            res_cnter[0] += 1 #Update/Accumulate

            self.dfsTraversal(root.left, root.val, res_cnter) #Recursion function call (i.e. root left-half node)
            self.dfsTraversal(root.right, root.val, res_cnter) #Recursion function call (i.e. root right-half node)

        else:
            self.dfsTraversal(root.left, record_max_val, res_cnter) #Recursion function call (i.e. root left-half node)
            self.dfsTraversal(root.right, record_max_val, res_cnter) #Recursion function call (i.e. root right-half node)
