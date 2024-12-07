# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def pathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (not root): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        record_dict = {0: 1}

        ##### Result summary counter #####
        res_cnter = [0]


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        self.dfsTraversal(root, record_dict, 0, targetSum, res_cnter) #Recursion function call (i.e. whole root node)

        return res_cnter[0]


    def dfsTraversal(self, root, record_dict, record_prefix_sum, targetSum, res_cnter):
        """
        :type root: Optional[TreeNode]
        :type record_dict: dict
        :type record_prefix_sum: int
        :type targetSum: int
        :type res_cnter: List
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ############
        #Initialize
        ##### Current prefix-summary value #####
        curr_prefix_sum = (record_prefix_sum + root.val)

        ####################
        #Whole process/flow
        ##### Check if the current prefix-summary existed or not #####
        if ((curr_prefix_sum - targetSum) in record_dict):
            res_cnter[0] += record_dict[(curr_prefix_sum - targetSum)] #Update/Accumulate

        ##### Check if the current prefix-summary existed or not #####
        if (curr_prefix_sum not in record_dict):
            record_dict[curr_prefix_sum] = 1 #Update/Record
        else:
            record_dict[curr_prefix_sum] += 1 #Update/Record

        if (root.left):
            self.dfsTraversal(root.left, record_dict, curr_prefix_sum, targetSum, res_cnter) #Recursion function call (i.e. root left-half node)

        if (root.right):
            self.dfsTraversal(root.right, record_dict, curr_prefix_sum, targetSum, res_cnter) #Recursion function call (i.e. root right-half node)

        record_dict[curr_prefix_sum] -= 1 #Update/Record
