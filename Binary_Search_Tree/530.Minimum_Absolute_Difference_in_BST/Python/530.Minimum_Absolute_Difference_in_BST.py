# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def getMinimumDifference(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record array #####
        record_arry = []

        ##### Result minimun difference #####
        res_min_diff = ((10 ** 9) + 1)


        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, record_arry) #Recursion function call (i.e. whole root tree-node)

        for record_idx in range((len(record_arry) - 1)):
            res_min_diff = min(res_min_diff, abs(record_arry[record_idx] - record_arry[(record_idx + 1)])) #Keep updating/overwriting

        return res_min_diff


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

        ####################
        #Whole process/flow
        self.dfsTraversal((root.left), record_arry) #Recursion function call (i.e. root left-half node)

        record_arry.append(root.val) #Update/Record

        self.dfsTraversal((root.right), record_arry) #Recursion function call (i.e. root right-half node)
