# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def diameterOfBinaryTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (root and (not root.left) and (not root.right)): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Result maximun summary counter ######
        res_max_cnter = [0]

        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, res_max_cnter) #Recursion function call

        return res_max_cnter[0]


    def dfsTraversal(self, root, res_max_cnter):
        """
        :type root: Optional[TreeNode]
        :type res_max_cnter: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return 0
        
        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling
            return 1

        ####################
        #Whole process/flow
        record_left_cnter = self.dfsTraversal(root.left, res_max_cnter) #Recursion function call (i.e. root left-half node)
        record_right_cnter = self.dfsTraversal(root.right, res_max_cnter) #Recursion function call (i.e. root right-half node)

        res_max_cnter[0] = max(res_max_cnter[0], (record_left_cnter + record_right_cnter)) #Keep updating/overwriting

        return (max(record_left_cnter, record_right_cnter) + 1)
