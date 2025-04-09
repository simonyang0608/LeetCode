# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumEvenGrandparent(self, root):
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

        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, res_sum_val) #Recursion function call (i.e. whole root-node)

        return res_sum_val[0]


    def dfsTraversal(self, root, res_sum_val):
        """
        :type root: Optional[TreeNode]
        :type res_sum_val: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ####################
        #Whole process/flow
        ##### Check if the current child-nodes existed or not #####
        if (root.left):

            ##### Check if the current grand child-nodes existed or not #####
            if ((root.left).left):

                ##### Check if the current grand parent-node is even or not #####
                if (not (root.val % 2)):
                    res_sum_val[0] += (((root.left).left).val) #Keep updating/accumulating

            if ((root.left).right):

                ##### Check if the current grand parent-node is even or not #####
                if (not (root.val % 2)):
                    res_sum_val[0] += (((root.left).right).val) #Keep updating/accumulating

            self.dfsTraversal(root.left, res_sum_val) #Recursion function call (i.e. root left-half node)

        if (root.right):

            ##### Check if the current grand child-nodes existed or not #####
            if ((root.right).left):

                ##### Check if the current grand parent-node is even or not #####
                if (not (root.val % 2)):
                    res_sum_val[0] += (((root.right).left).val) #Keep updating/accumulating

            if ((root.right).right):

                ##### Check if the current grand parent-node is even or not #####
                if (not (root.val % 2)):
                    res_sum_val[0] += (((root.right).right).val) #Keep updating/accumulating

            self.dfsTraversal(root.right, res_sum_val) #Recursion function call (i.e. root right-half node)
