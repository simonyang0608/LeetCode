# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def longestZigZag(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Result array #####
        res_arry = [0]

        ####################################
        #Recursion-based DFS loop traversal
        ##### Check if the current left,right tree-node existed or not #####
        if (root.left):
            self.dfsTraversal(root.left, 0, 1 ,res_arry) #Recursion function call (i.e. root left-half node)

        if (root.right):
            self.dfsTraversal(root.right, 1, 1, res_arry) #Recursion function call (i.e. root right-half node)

        return res_arry[0]


    def dfsTraversal(self, root, record_direc, record_path, res_arry):
        """
        :type root: Optional[TreeNode]
        :type record_direc: bool
        :type record_path: int
        :type res_arry: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (record_path > res_arry[0]): 
            res_arry[0] = record_path #Update/Overwrite

        ####################
        #Whole process/flow
        ##### Check if the current directions is left or right #####
        if (record_direc == 0):

            ##### Check if the next tree-node (i.e. left, right-half) existed or not #####
            if (root.right):
                self.dfsTraversal(root.right, 1, (record_path + 1), res_arry) #Recursion function call (i.e. root right-half node)
            if (root.left):
                self.dfsTraversal(root.left, 0, 1, res_arry) #Recursion function call (i.e. root left-half node)

        else:
            ##### Check if the next tree-node (i.e. left, right-half) existed or not #####
            if (root.right):
                self.dfsTraversal(root.right, 1, 1, res_arry) #Recursion function call (i.e. root right-half node)
            if (root.left):
                self.dfsTraversal(root.left, 0, (record_path + 1), res_arry) #Recursion function call (i.e. root left-half node)
