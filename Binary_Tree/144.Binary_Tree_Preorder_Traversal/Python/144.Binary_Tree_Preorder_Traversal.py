# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        #======================================#
        # Resursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Result array #####
        res_arry = []

        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, res_arry) #Recursion function call (i.e. whole node)

        return res_arry


    def dfsTraversal(self, root, res_arry):
        """
        :type root: TreeNode
        :type res_arry: List[int]
        :rtype: None, void
        """
        #========================================#
        # Resursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        res_arry.append((root.val)) #Update/Record

        self.dfsTraversal((root.left), res_arry) #Recursion fucntion call (i.e. root left-half node)
        self.dfsTraversal((root.right), res_arry) #Recursion fucntion call (i.e. root right-half node)
