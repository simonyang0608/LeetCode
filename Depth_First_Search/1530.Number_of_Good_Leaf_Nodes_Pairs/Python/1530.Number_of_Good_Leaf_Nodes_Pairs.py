# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def countPairs(self, root, distance):
        """
        :type root: TreeNode
        :type distance: int
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Result summary counter #####
        res_cnter = [0]

        ####################################
        #Recursion-based DFS loop traversal
        res_arry = self.dfsTraversal(root, distance, res_cnter) #Recursion function call (i.e. whole root node)

        return res_cnter[0]


    def dfsTraversal(self, root, distance, res_cnter):
        """
        :type root: TreeNode
        :type distance: int
        :type res_cnter: List[int]
        :rtype: Nonr, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return []

        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling
            return [1]


        ############
        #Initialize
        ##### Result array #####
        res_arry = []

        ####################
        #Whole process/flow
        left_arry = self.dfsTraversal(root.left, distance, res_cnter) #Recursion function call (i.e. root left-half node)
        right_arry = self.dfsTraversal(root.right, distance, res_cnter) #Recursion function call (i.e. root right-half node)

        for left_idx in range(len(left_arry)):
            for right_idx in range(len(right_arry)):

                ##### Check if the current inner distance matched conditions or not #####
                if ((left_arry[left_idx] + right_arry[right_idx]) <= distance):
                    res_cnter[0] += 1 #Keep updating/accumulating
                else:
                    pass

        record_arry = (left_arry + right_arry) #Update/Concate

        for record_idx in range(len(record_arry)):

            ##### Check if the current inner distance matched conditions or not #####
            if ((record_arry[record_idx] + 1) <= distance):
                res_arry.append((record_arry[record_idx] + 1)) #Keep updating/recording
            else:
                pass

        return res_arry
