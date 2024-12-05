# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (not root): #Issue/Boundary-case handling
            return True

        ############
        #Initialize
        ##### Record flag #####
        record_flag = [True]

        ####################################
        #Recursion-based DFS loop traversal
        res_height = self.dfsTraversal(root, record_flag) #Recursion function call (i.e. whole root node)

        return record_flag[0]
        

    def dfsTraversal(self, root, record_flag):
        """
        :type root: Optional[TreeNode]
        :type record_flag: List[bool]
        :rtype: int
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return 0

        ####################
        #Whole process/flow
        root_left_height = self.dfsTraversal(root.left, record_flag) #Recursion function call (i.e. root left-half node)
        root_right_height = self.dfsTraversal(root.right, record_flag) #Recursion function call (i.e. root right-half node)

        ##### Check if the current height differences matched conditions or not #####
        if (abs(root_left_height - root_right_height) > 1):
            if (record_flag[0]):
                record_flag[0] &= False #Update/Overwrite

        return (max(root_left_height, root_right_height) + 1)
