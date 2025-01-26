# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """

        return self.dfsTraversal(root, p, q) #Recursion function call (i.e. whole root tree-node)
        

    def dfsTraversal(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        if ((not root) or (root == p) or (root == q)): #Issue/Boundary-case handling
            return root

        ####################
        #Whole process/flow
        root_left = self.dfsTraversal((root.left), p, q) #Recursion function call (i.e. root left-half node)
        root_right = self.dfsTraversal((root.right), p, q) #Recursion function call (i.e. root right-half node)

        ##### Check if the current sub root tree-node matched conditions or not #####
        if (root_left and root_right):
            return root

        if (root_left):
            return root_left

        if (root_right):
            return root_right

        return root_left
