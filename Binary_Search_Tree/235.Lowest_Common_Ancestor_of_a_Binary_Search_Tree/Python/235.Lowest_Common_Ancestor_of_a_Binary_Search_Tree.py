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
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record maximun root-node value #####
        record_max_val = (p.val if (p.val > q.val) else q.val)

        ##### Record minimun root-node value #####
        record_min_val = (p.val if (p.val < q.val) else q.val)


        ####################################
        #Binary-search based loop traversal
        while (root):

            ##### Check if the current root-node value matched conditions or not #####
            if (root.val > record_max_val):
                root = root.left #Keep updating/traversing

            elif (root.val < record_min_val):
                root = root.right #Keep updating/traversing

            else:
                return root

        return None
