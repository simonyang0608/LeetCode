# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isValidBST(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record value #####
        record_val = [(((-1) * (2 ** 31)) - 1)]

        ##### Record flag #####
        record_flag = [True]


        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, record_val, record_flag) #Recursion function call (i.e. whole root tree-node)

        return record_flag[0]


    def dfsTraversal(self, root, record_val, record_flag):
        """
        :type root: Optional[TreeNode]
        :type record_val: int
        :type record_flag: bool
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        self.dfsTraversal(root.left, record_val, record_flag) #Recursion function call (i.e. root left-half node)

        ##### Check if the current value is larger or not #####
        if (root.val <= record_val[0]):

            ##### Check if the current flag needs to be overwrite or not #####
            if (record_flag[0]):
                record_flag[0] &= False #Update/Overwrite
            else:
                pass
        else:
            pass

        record_val[0] = root.val #Update/Overwrite

        self.dfsTraversal(root.right, record_val, record_flag) #Recursion function call (i.e. root right-half node)
