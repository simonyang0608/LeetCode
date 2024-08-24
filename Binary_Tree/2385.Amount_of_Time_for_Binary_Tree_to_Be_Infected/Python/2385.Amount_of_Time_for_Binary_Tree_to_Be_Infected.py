# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def amountOfTime(self, root, start):
        """
        :type root: Optional[TreeNode]
        :type start: int
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Result array #####
        res_arry = [0]

        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, start, res_arry) #Resursion function call (i.e. whole node)

        return res_arry[0]


    def dfsTraversal(self, root, start, res_arry):
        """
        :type root: Optional[TreeNode]
        :type start: int
        :type res_arry: List[int]
        :rtype: int
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return 0

        ####################
        #Whole process/flow
        root_left = self.dfsTraversal((root.left), start, res_arry) #Recursion function call (i.e. root left-half node)
        root_right = self.dfsTraversal((root.right), start, res_arry) #Recursion function call (i.e. root right-half node)

        ##### Check if the current root (i.e. left/right-half) matched conditions or not #####
        if ((root.val) == start): #Start point/node
            res_arry[0] = max(res_arry[0], (max(root_left, root_right))) #Update/Overwrite

            return (-1)

        elif ((root_left < 0) or (root_right < 0)): #Upon start point/node
            res_arry[0] = max(res_arry[0], (abs(root_left) + abs(root_right))) #Update/Overwrite

            return (min(root_left, root_right) - 1)

        elif ((root_left >= 0) and (root_right >= 0)): #Below start point/node
            res_arry[0] = max(res_arry[0], (max(root_left, root_right) + 1)) #Update/Overwrite

            return (max(root_left, root_right) + 1)
