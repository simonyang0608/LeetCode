# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def deleteNode(self, root, key):
        """
        :type root: Optional[TreeNode]
        :type key: int
        :rtype: Optional[TreeNode]
        """
        #==================================#
        # Recursion-based traversal method #
        #==================================#
        if (not root): #Issue/Boundary-case handling
            return None

        ################################
        #Recursion-based loop traversal
        if ((root.val) < key):
            root.right = self.deleteNode((root.right), key) #Root right-half node traversal

        elif ((root.val) > key):
            root.left = self.deleteNode((root.left), key) #Root left-half node traversal

        else:
            if ((not root.left) and (not root.right)):
                root = None #Update/Overwrite

            elif (root.right):
                root.val = self.successor(root) #Update/Overwrite
                root.right = self.deleteNode((root.right), root.val) #Root right-half node

            else:
                root.val = self.preceedor(root) #Update/Overwrite
                root.left = self.deleteNode((root.left), root.val) #Root left-half node

        return root


    def successor(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #====================================#
        # Root right-half traversal function #
        #====================================#

        ############
        #Initialize
        ##### Right-half tree-node root #####
        root_right = root.right

        ####################
        #Whole process/flow
        while (root_right.left):
            root_right = root_right.left #Keep updating/overwriting

        return root_right.val


    def preceedor(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: Optional[TreeNode]
        """
        #===================================#
        # Root left-half traversal function #
        #===================================#

        ############
        #Initialize
        ##### Left-half tree-node root #####
        root_left = root.left

        ####################
        #Whole process/flow
        while (root_left.right):
            root_left = root_left.right #Keep updating/overwriting

        return root_left.val
