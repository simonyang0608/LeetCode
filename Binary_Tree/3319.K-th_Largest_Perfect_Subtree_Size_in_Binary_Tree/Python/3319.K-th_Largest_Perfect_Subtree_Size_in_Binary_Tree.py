# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthLargestPerfectSubtree(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
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
        self.dfsTraversal(root, res_arry) #Recursion function call (i.e. whole tree-node)

        ##### Check if the current array matched conditions or not #####
        if (len(res_arry) < k):
            return (-1)

        res_arry.sort(reverse = True) #Sorted operations

        return res_arry[(k - 1)]


    def dfsTraversal(self, root, res_arry):
        """
        :type root: Optional[TreeNode]
        :type res_arry: List[int]
        :rtype: int
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return (-1)

        if ((not (root.left)) and (not (root.right))): #Issue/Boundary-case handling
            res_arry.append(1) #Update/Record

            return 1

        ####################
        #Whole process/flow
        root_left = self.dfsTraversal((root.left), res_arry) #Recursion function call (i.e. root left-half node)
        root_right = self.dfsTraversal((root.right), res_arry) #Recursion function call (i.e. root right-half node)

        ##### Check if the current tree-node matched conditions or not #####
        if (((root_left == (-1)) or (root_right == (-1))) or (root_left != root_right)): #Not perfect sub-tree node
            return (-1)

        elif (root_left == root_right): #Is prefect sub-tree node
            res_arry.append((root_left + root_right + 1)) #Update/Record

            return ((root_left + root_right + 1))
