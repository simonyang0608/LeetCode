# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: List[List[int]]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Result array #####
        res_arry = []

        if (not root): #Issue/Boundary-case handling
            return res_arry


        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, [root.val], res_arry, targetSum) #Recursion function call (i.e. whole root node)

        return res_arry
        

    def dfsTraversal(self, root, record_arry, res_arry, targetSum):
        """
        :type root: Optional[TreeNode]
        :type record_arry: List[int]
        :type res_arry: List[List[int]]
        :type targetSum: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling

            ##### Check if the current summary matched conditions or not #####
            if (sum(record_arry) == targetSum):
                res_arry.append(record_arry) #Update/Record

        ####################
        #Whole process/flow
        if (root.left):
            self.dfsTraversal(root.left, (record_arry + [(root.left).val]), res_arry, targetSum) #Recursion function call (i.e. root left-half node)

        if (root.right):
            self.dfsTraversal(root.right, (record_arry + [(root.right).val]), res_arry, targetSum) #Recursion function call (i.e. root right-half node)
