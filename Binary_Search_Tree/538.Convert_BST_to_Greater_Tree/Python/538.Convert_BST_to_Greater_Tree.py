# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def convertBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (not root): #Issue/Boundary-case handling
            return None

        ############
        #Initialize
        ##### Record summary value #####
        record_sum_val = [0]

        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, record_sum_val) #Recursion function call (i.e. whole root tree-node)

        return root

    
    def dfsTraversal(self, root, record_sum_val):
        """
        :type root: Optional[TreeNode]
        :type record_sum_val: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        self.dfsTraversal(root.right, record_sum_val) #Recursion function call (i.e. root right-half node)

        record_sum_val[0] += root.val #Update/Accumulate

        root.val = record_sum_val[0] #Update/Overwrite

        self.dfsTraversal(root.left, record_sum_val) #Recursion function call (i.e. root left-half node)
