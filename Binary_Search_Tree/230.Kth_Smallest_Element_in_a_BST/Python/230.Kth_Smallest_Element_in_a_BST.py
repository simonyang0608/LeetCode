# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def kthSmallest(self, root, k):
        """
        :type root: Optional[TreeNode]
        :type k: int
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#
        
        ############
        #Initialize
        ##### Record stack array #####
        record_stack = []

        ############################
        #Stack-based loop traversal
        while (root or record_stack):
            while (root):
                record_stack.append(root) #Keep updating/recording

                root = root.left #Keep updating/overwriting

            record_root = record_stack.pop() #Record root tree-node

            k -= 1 #Keep updating/reducing

            ##### Check if the current order matched conditions or not #####
            if (not k):
                return record_root.val

            root = record_root.right #Keep updating/overwriting

        return (-1)
