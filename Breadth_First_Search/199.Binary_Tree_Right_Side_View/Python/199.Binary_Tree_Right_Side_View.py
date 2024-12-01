# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def rightSideView(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        #======================================#
        # Recursion-based BFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record array #####
        record_arry = []

        ##### Result array #####
        res_arry = []


        ####################################
        #Recursion-based BFS loop traversal
        ##### Step 1: Recursion function call for the whole tree-node #####
        self.bfsTraversal(root, record_arry, 1)

        ##### Step 2: Post-process, completions #####
        len_record_arry = len(record_arry) #Length of record array

        for record_arry_idx in range(len_record_arry):
            res_arry.append((record_arry[record_arry_idx])[(-1)]) #Keep updating/recording

        return res_arry


    def bfsTraversal(self, root, record_arry, level):
        """
        :type root: Optional[TreeNode]
        :type record_arry: List[List[int]]
        :type level: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based BFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        ##### Check if the current level matched conditions or not #####
        if (level > len(record_arry)):
            record_arry.append([root.val]) #Update/Record
        else:
            (record_arry[(level - 1)]).append(root.val) #Update/Record

        self.bfsTraversal((root.left), record_arry, (level + 1)) #Recursion fucntion call (i.e. root left-half node)
        self.bfsTraversal((root.right), record_arry, (level + 1)) #Recursion fucntion call (i.e. root right-half node)
