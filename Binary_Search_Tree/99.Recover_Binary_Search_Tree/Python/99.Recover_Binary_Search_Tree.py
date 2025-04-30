# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def recoverTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: None Do not return anything, modify root in-place instead.
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Record stack #####
        record_stack = []

        ##### Previous root tree-node #####
        prev_node = None

        ##### Result first, second root tree-node #####
        res_first_node, res_second_node = None, None


        ############################
        #Stack-based loop traversal
        while (record_stack or root):
            while (root):
                record_stack.append(root) #Keep updating/recording

                root = root.left #Keep updating/traversing

            ##### Check if the previous tree-node existed or not #####
            if (not prev_node):
                pass
            else:
                ##### Check if the previous tree-node matched conditions or not #####
                if (prev_node.val > (record_stack[(-1)]).val):

                    ##### Check if the current tree-node existed or not #####
                    if (not res_first_node):
                        res_first_node = prev_node #Keep updating/overwriting
                    else:
                        pass

                    res_second_node = record_stack[(-1)] #Keep updating/overwriting

            prev_node = record_stack.pop() #Keep updating/overwriting

            root = prev_node.right #Keep updating/traversing

        res_first_node.val, res_second_node.val = res_second_node.val, res_first_node.val #Swapped operations
