# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def averageOfLevels(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[float]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Record queue #####
        record_queue = [root]

        ##### Result array #####
        res_arry = []


        ##########################################
        #Breath-first search based loop traversal
        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            record_sum_val = 0. #Record summary value

            for queue_idx in range(queue_size):
                record_root = record_queue.pop(0) #Record root

                record_sum_val += record_root.val #Keep updating/accumulating

                ##### Check if the root left-half node existed or not #####
                if (record_root.left):
                    record_queue.append(record_root.left) #Keep updating/recording
                else:
                    pass

                ##### Check if the root right-half node existed or not #####
                if (record_root.right):
                    record_queue.append(record_root.right) #Keep updating/recording
                else:
                    pass

            res_arry.append((record_sum_val / queue_size)) #Keep updating/recording

        return res_arry
