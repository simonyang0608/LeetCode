# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def trimBST(self, root, low, high):
        """
        :type root: Optional[TreeNode]
        :type low: int
        :type high: int
        :rtype: Optional[TreeNode]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        return self.dfsTraversal(root, low, high) #Recursion function call


    def dfsTraversal(self, root, low, high):
        """
        :type root: Optional[TreeNode]
        :type low: int
        :type high: int
        :rtype: Optional[TreeNode]
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (not root): #Issue/Boundary-case handling
            return None

        if (((root.val >= low) and (root.val <= high)) and ((not root.left) and (not root.right))): #Issue/Boundary-case handling
            return root

        ####################
        #Whole process/flow
        root.left = self.dfsTraversal(root.left, low, high) #Recursion function call (i.e. root left-half node)
        root.right = self.dfsTraversal(root.right, low, high) #Recursion function call (i.e. root right-half node)

        ##### Check if the current value matched conditions or not #####
        if ((root.val < low) or (root.val > high)):

            ##### Check if the current root left, right-half node existed or not #####
            if (root.right):
                return self.successor(root)

            elif (root.left):
                return self.preceedor(root)

            return None

        return root


    def successor(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        #==============================#
        # Root node successor function #
        #==============================#

        ############
        #Initialize
        ##### Result root node #####
        root_left, root_right = root.left, root.right
        res_root_right = root_right

        ####################
        #Whole process/flow
        ##### Check if the current root node matched conditions or not #####
        if (root.left):
            root.left = None #Update/Overwrite
        else:
            pass

        root.right = None #Update/Overwrite

        while (root_right.left):
            root_right = root_right.left #Update/Overwrite

        root_right.left = root_left #Update/Overwrite

        return res_root_right


    def preceedor(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        #==============================#
        # Root node successor function #
        #==============================#

        ####################
        #Whole process/flow
        res_root_left = root.left #Update/Overwrite

        root.left = None #Update/Overwrite

        return res_root_left
