# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def __init__(self):
        """
        :type None: void
        :rtype: None, void
        """
        ############
        #Initialize
        ##### Record array #####
        self.record_arry = []

    def maxLevelSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Result maximun value #####
        res_max_val = ((-1) * ((10 ** 5) - 1))

        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, 1) #Recursion function call (i.e. whole root tree-node)

        for record_idx in range(len(self.record_arry)):

            ##### Check if the current summary value is larger or not #####
            if (((self.record_arry)[record_idx])[0] > res_max_val):
                res_max_val = ((self.record_arry)[record_idx])[0] #Keep updating/overwriting
            else:
                pass

        for record_idx in range(len(self.record_arry)):

            ##### Check if the current summary value matched conditions or not #####
            if (((self.record_arry)[record_idx])[0] == res_max_val):
                return (record_idx + 1)

        return (-1)


    def dfsTraversal(self, root, record_idx):
        """
        :type root: Optional[TreeNode]
        :type record_idx: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ##### Check if the current level exceeds boundary or not #####
        if (len(self.record_arry) < record_idx):
            (self.record_arry).append([root.val]) #Update/Record
        else:
            ((self.record_arry)[(record_idx - 1)])[0] += root.val #Update/Overwrite

        self.dfsTraversal((root.left), (record_idx + 1)) #Recursion function call (i.e. root left-half node)
        self.dfsTraversal((root.right), (record_idx + 1)) #Recursion function call (i.e. root right-half node)
