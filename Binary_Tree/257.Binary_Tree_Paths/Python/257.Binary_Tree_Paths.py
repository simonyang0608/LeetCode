# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def binaryTreePaths(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[str]
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
        self.dfsTraversal(root, str(root.val), res_arry) #Recursion function call (i.e. whole root tree-node)

        return res_arry


    def dfsTraversal(self, root, record_str, res_arry):
        """
        :type root: Optional[TreeNode]
        :type record_str: str
        :type res_arry: List[str]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling
            res_arry.append(record_str) #Update/Record

            return

        ##### Check if the next root left-half node existed or not ##### 
        if (root.left):
            self.dfsTraversal(root.left, (record_str + "->" + str((root.left).val)), res_arry) #Recursion function call (i.e. root left-half node)

        ##### Check if the next root right-half node existed or not #####
        if (root.right):
            self.dfsTraversal(root.right, (record_str + "->" + str((root.right).val)), res_arry) #Recursion function call (i.e. root right-half node)
