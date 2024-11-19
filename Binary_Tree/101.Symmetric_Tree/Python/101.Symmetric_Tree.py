# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSymmetric(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if ((not root.left) and (not root.right)): #Issue/Boundary-case handling
            return True

        ############
        #Initialize
        ##### Result array (left, right-half) #####
        res_left_arry, res_right_arry = [], []

        ####################################
        #Recursion-based DFS loop traversal
        self.preorderLeft(root, root, res_left_arry) #Recursion function call (i.e. root left-half node)
        self.preorderRight(root, root, res_right_arry) #Recursion function call (i.e. root right-half node)

        return (True if (res_left_arry == res_right_arry) else False)


    def preorderLeft(self, root, main_root, res_left_arry):
        """
        :type root: Optional[TreeNode]
        :type main_root: Optional[TreeNode]
        :type res_left_arry: List[int]
        :rtype: None, Void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            res_left_arry.append((-1)) #Update/Record

            return

        ####################
        #Whole process/flow
        res_left_arry.append(root.val) #Update/Record

        self.preorderLeft(root.left, main_root, res_left_arry) #Recursion function call (i.e. root left-half node)

        if (root == main_root): #Issue/Boundary-case handling
            return

        self.preorderLeft(root.right, main_root, res_left_arry) #Recursion function call (i.e. root right-half node)

    
    def preorderRight(self, root, main_root, res_right_arry):
        """
        :type root: Optional[TreeNode]
        :type main_root: Optional[TreeNode]
        :type res_right_arry: List[int]
        :rtype: None, Void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            res_right_arry.append((-1)) #Update/Record

            return

        ####################
        #Whole process/flow
        res_right_arry.append(root.val) #Update/Record

        self.preorderRight(root.right, main_root, res_right_arry) #Recursion function call (i.e. root right-half node)

        if (root == main_root): #Issue/Boundary-case handling
            return

        self.preorderRight(root.left, main_root, res_right_arry) #Recursion function call (i.e. root left-half node)
