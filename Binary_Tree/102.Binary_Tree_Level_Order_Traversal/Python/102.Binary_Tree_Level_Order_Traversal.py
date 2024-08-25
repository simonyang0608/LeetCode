# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        #======================================#
        # Recursion-based BFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Result array #####
        res_arry = []

        ####################################
        #Recursion-based BFS loop traversal
        self.bfsTraversal(root, 1, res_arry) #Recursion function call (i.e. whole node)

        return res_arry


    def bfsTraversal(self, root, level, res_arry):
        """
        :type root: TreeNode
        :type level: int
        :type res_arry: List[List[int]]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based BFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        ##### Step 1: Check if the current level matched conditions or not #####
        if (len(res_arry) < level):
            res_arry.append([(root.val)]) #Update/Record
        else:
            (res_arry[(level -1)]).append((root.val)) #Update/Record

        ##### Step 2: Recursion-based BFS loop traversal #####
        self.bfsTraversal((root.left), (level + 1), res_arry) #Recursion function call (i.e. root left-half node)
        self.bfsTraversal((root.right), (level + 1), res_arry) #Recursion function call (i.e. root right-half node)
