# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def findFrequentTreeSum(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record maximun summary counter #####
        record_max_cnter = [(-1)]

        ##### Result array #####
        res_arry = []


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        res_sum_val = self.dfsTraversal(root, record_dict, record_max_cnter) #Recursion function call (i.e. whole root tree-node)

        for record_key in record_dict:

            ##### Check if the current summary counter matched conditions or not #####
            if (record_dict[record_key] == record_max_cnter[0]):
                res_arry.append(record_key) #Keep updating/recording
            else:
                pass

        return res_arry


    def dfsTraversal(self, root, record_dict, record_max_cnter):
        """
        :type root: Optional[TreeNode]
        :type record_dict: dict
        :type record_max_cnter: List[int]
        :rtype: int
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return 0

        ####################
        #Whole process/flow
        root_left_val = self.dfsTraversal(root.left, record_dict, record_max_cnter) #Recursion function call (i.e. root left-half node)
        root_right_val = self.dfsTraversal(root.right, record_dict, record_max_cnter) #Recursion function call (i.e. root right-half node)

        record_sum_val = (root.val + root_left_val + root_right_val) #Record summary value

        ##### Check if the current summary value existed or not #####
        if (record_sum_val not in record_dict):
            record_dict[record_sum_val] = 1 #Keep updating/recording
        else:
            record_dict[record_sum_val] += 1 #Keep updating/recording

        record_max_cnter[0] = (record_dict[record_sum_val] if (record_dict[record_sum_val] > 
                               record_max_cnter[0]) else record_max_cnter[0]) #Keep updating/overwriting

        return record_sum_val
