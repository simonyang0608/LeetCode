# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def countNodes(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #==============================#
        # Queue-based traversal method #
        #==============================#
        if (not root): #Issue/Boundary-case handling
            return 0
        
        ############
        #Initialize
        ##### Record queue #####
        record_queue = [root]

        ##### Length of queue #####
        len_queue = 1

        ##### Record traversal index #####
        record_trav_idx = 0

        ##### Result summary counter #####
        res_cnter = 0


        ############################
        #Queue-based loop traversal
        while (record_trav_idx < len_queue):
            curr_node = record_queue[record_trav_idx] #Current tree-node

            res_cnter += 1 #Keep updating/accumulating

            ##### Check if the current tree-node matched conditions or not #####
            if ((curr_node.left)): #Left-half
                record_queue.append((curr_node.left)) #Keep updating/recording

                len_queue += 1 #Keep updating/accumulating
            else:
                pass

            if ((curr_node.right)): #Right-half
                record_queue.append((curr_node.right)) #Keep updating/recording

                len_queue += 1 #Keep updating/accumulating
            else:
                pass

            record_trav_idx += 1 #Keep updating/accumulating

        return res_cnter
