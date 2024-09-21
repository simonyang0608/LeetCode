# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Result array #####
        res_arry = []

        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, res_arry) #Recursion function call (i.e. while root node)

        len_res_arry = len(res_arry) #Length of result array
        len_res_arry -= 1

        for res_node_idx in range(len_res_arry):
            (res_arry[res_node_idx]).right = res_arry[(res_node_idx + 1)] #Keep updating/overwriting


    def dfsTraversal(self, root, res_arry):
        """
        :type root: TreeNode
        :type res_arry: List[TreeNode]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return 

        root_left, root_right = (root.left), (root.right) #Root left, right half node

        (root.left) = None #Reset
        (root.right) = None #Reset

        res_arry.append(root) #Update/Record

        self.dfsTraversal(root_left, res_arry) #Recursion function call (i.e. root left-half node)
        self.dfsTraversal(root_right, res_arry) #Recursion function call (i.e. root right-half node)
