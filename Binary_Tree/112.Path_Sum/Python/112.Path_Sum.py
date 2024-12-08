# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def hasPathSum(self, root, targetSum):
        """
        :type root: Optional[TreeNode]
        :type targetSum: int
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (not root): #Issue/Boundary-case handling
            return False

        ############
        #Initialize
        ##### Record summary value #####
        record_sum_val = [root.val]

        ##### Result flag #####
        res_flag = [False]


        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(root, record_sum_val, targetSum, res_flag) #Recursion function call (i.e. whole root node)

        return res_flag[0]


    def dfsTraversal(self, root, record_sum_val, targetSum, res_flag):
        """
        :type root: Optional[TreeNode]
        :type record_sum_val: List[int]
        :type targetSum: int
        :type res_flag: List[bool]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling

            ##### Check if the current summary value matched conditions or not #####
            if (record_sum_val[0] == targetSum):

                ##### Check if the current flag matched conditions or not #####
                if (not res_flag[0]):
                    res_flag[0] |= True #Update/Overwrite
        
        #####################
        #Whole process/flow
        if (root.left):
            record_sum_val[0] += ((root.left).val) #Update/Accumulate

            self.dfsTraversal(root.left, record_sum_val, targetSum, res_flag) #Recursion function call (i.e. root left-half node)

        if (root.right):
            record_sum_val[0] += ((root.right).val) #Update/Accumulate

            self.dfsTraversal(root.right, record_sum_val, targetSum, res_flag) #Recursion function call (i.e. root right-half node)

        record_sum_val[0] -= root.val #Update/Reduce
