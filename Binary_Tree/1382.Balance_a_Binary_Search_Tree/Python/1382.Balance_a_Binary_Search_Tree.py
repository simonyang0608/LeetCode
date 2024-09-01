# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def balanceBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
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
        self.dfsTraversal(root, res_arry) #Recursion function call (i.e. whole node)

        return self.treeTraversal(0, (len(res_arry) - 1), res_arry)


    def dfsTraversal(self, root, res_arry):
        """
        :type root: TreeNode
        :type res_arry: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        self.dfsTraversal((root.left), res_arry) #Recursion function call (i.e. root left-half node)

        res_arry.append((root.val)) #Update/Record

        self.dfsTraversal((root.right), res_arry) #Recursion function call (i.e. root right-half node)


    def treeTraversal(self, left_low, right_high, res_arry):
        """
        :type res_arry: List[int]
        :rtype: res_root: TreeNode
        """
        #=========================================#
        # Recursion-based tree traversal function #
        #=========================================#
        if (left_low > right_high): #Issue/Boundary-case handling
            return

        ############
        #Initialize
        ##### Middle index #####
        middle_idx = ((left_low + right_high) // 2)

        ####################
        #Whole process/flow
        root = TreeNode(res_arry[middle_idx]) #Root node

        (root.left) = self.treeTraversal(left_low, (middle_idx - 1), res_arry) #Recursion function call (i.e. root left-half node)
        (root.right) = self.treeTraversal((middle_idx + 1), right_high, res_arry) #Recursion function call (i.e. root left-half node)

        return root
