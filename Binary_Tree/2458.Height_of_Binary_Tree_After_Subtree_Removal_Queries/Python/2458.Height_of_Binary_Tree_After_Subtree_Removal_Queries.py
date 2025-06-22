# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def treeQueries(self, root, queries):
        """
        :type root: Optional[TreeNode]
        :type queries: List[int]
        :rtype: List[int]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of queries array #####
        len_queries = len(queries)

        ##### Record dictionary/hashmaps (i.e. left, right) #####
        left_dict, right_dict = {}, {}

        ##### Record maximun depths (i.e. left, right) #####
        left_max_depth, right_max_depth = [0], [0]

        ##### Result array #####
        res_arry = [0 for _ in range(len_queries)]


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-roots informations with dictionary/hashmap #####
        self.dfsLeft(root, left_dict, 0, left_max_depth) #Recursion function call (i.e. root left-half node)
        self.dfsRight(root, right_dict, 0, right_max_depth) #Recursion function call (i.e. root right-half node)

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for queries_idx in range(len_queries):
            res_arry[queries_idx] = max(left_dict[queries[queries_idx]], right_dict[queries[queries_idx]]) #Keep updating/overwriting

        return res_arry


    def dfsLeft(self, root, left_dict, left_depth, left_max_depth):
        """
        :type root: Optional[TreeNode]
        :type left_dict: dict
        :type left_depth: int
        :type left_max_depth: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        left_dict[root.val] = left_max_depth[0] #Update/Overwrite

        left_max_depth[0] = max(left_max_depth[0], left_depth) #Update/Overwrite

        self.dfsLeft(root.left, left_dict, (left_depth + 1), left_max_depth) #Recursion function call (i.e. root left-half node)
        self.dfsLeft(root.right, left_dict, (left_depth + 1), left_max_depth) #Recursion function call (i.e. root right-half node)


    def dfsRight(self, root, right_dict, right_depth, right_max_depth):
        """
        :type root: Optional[TreeNode]
        :type right_dict: dict
        :type right_depth: int
        :type right_max_depth: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        right_dict[root.val] = right_max_depth[0] #Update/Overwrite

        right_max_depth[0] = max(right_max_depth[0], right_depth) #Update/Overwrite

        self.dfsRight(root.right, right_dict, (right_depth + 1), right_max_depth) #Recursion function call (i.e. root right-half node)
        self.dfsRight(root.left, right_dict, (right_depth + 1), right_max_depth) #Recursion function call (i.e. root left-half node)
