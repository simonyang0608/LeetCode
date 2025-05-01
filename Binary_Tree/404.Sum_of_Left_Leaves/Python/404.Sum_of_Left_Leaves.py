# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: int
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Record queue #####
        record_queue = [root]

        ##### Result summary value #####
        res_sum_val = 0


        ##########################################
        #Breath-first search based loop traversal
        while (record_queue):
            len_queue = len(record_queue) #Length of queue

            for queue_idx in range(len_queue):
                record_root = record_queue.pop(0) #Record root

                ##### Check if the next root left-half node existed or not #####
                if (record_root.left):

                    ##### Check if the root child-child node existed or not #####
                    if ((not (record_root.left).left) and (not (record_root.left).right)):
                        res_sum_val += (record_root.left).val #Keep updating/accumulating
                    else:
                        pass

                    record_queue.append(record_root.left) #Keep updating/recording
                else:
                    pass

                ##### Check if the next root right-half node existed or not #####
                if (record_root.right):
                    record_queue.append(record_root.right) #Keep updating/recording
                else:
                    pass

        return res_sum_val
