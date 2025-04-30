# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: List[List[int]]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Record queue #####
        record_queue = []

        ##### Result array #####
        res_arry = []


        ##########################################
        #Breath-first search based loop traversal
        if (not root): #Issue/Boundary-case handling
            return res_arry

        record_queue.append(root) #Update/Record

        while (record_queue):
            len_queue = len(record_queue) #Length of queue array

            record_arry = [] #Record array

            for queue_idx in range(len_queue):
                record_root = record_queue.pop(0) #Record root

                record_arry.append(record_root.val) #Keep updating/recording

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

            res_arry.append(record_arry) #Keep updating/recording

        return res_arry[:: (-1)]
