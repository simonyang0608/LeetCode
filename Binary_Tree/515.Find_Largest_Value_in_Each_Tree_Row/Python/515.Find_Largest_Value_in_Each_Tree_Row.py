# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def largestValues(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[int]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#
        if (not root): #Issue/Boundary-case handling
            return []

        ############
        #Initialize
        ##### Record queue #####
        record_queue = [root]

        ##### Result array #####
        res_arry = []


        ##########################################
        #Breath-first search based loop traversal
        while (record_queue):
            len_queue = len(record_queue) #Length of queue

            record_max_val = float("-inf") #Record maximun value 

            for queue_idx in range(len_queue):
                record_root = record_queue.pop(0) #Record root

                record_max_val = (record_root.val if (record_root.val > record_max_val) else record_max_val) #Keep updating/overwriting

                ##### Check if the next root left-half node existed or not #####
                if (record_root.left):
                    record_queue.append(record_root.left) #Keep updating/recording
                else:
                    pass

                ##### Check if the next root right-half node existed or not #####
                if (record_root.right):
                    record_queue.append(record_root.right) #Keep updating/recording
                else:
                    pass

            res_arry.append(record_max_val) #Keep updating/recording

        return res_arry
