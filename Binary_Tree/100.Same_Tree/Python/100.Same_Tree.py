# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: Optional[TreeNode]
        :type q: Optional[TreeNode]
        :rtype: bool
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Record queues (i.e. p, q) #####
        record_queue_p, record_queue_q = [p], [q]

        ##### Record boundary-value #####
        record_bound_val = (10 ** 5)


        ##########################################
        #Breath-first search based loop traversal
        while (record_queue_p and record_queue_q):
            len_queue_p, len_queue_q = len(record_queue_p), len(record_queue_q) #Length of queues (i.e. p, q)

            record_arry_p, record_arry_q = [], [] #Record arrays (i.e. p, q)

            for queue_pidx in range(len_queue_p):
                record_root_p = record_queue_p.pop(0) #Record root (i.e. p)

                ##### Check if the current root tree-node existed or not #####
                if (not record_root_p):
                    record_arry_p.append(record_bound_val) #Keep updating/recording
                else:
                    record_arry_p.append(record_root_p.val) #Keep updating/recording

                    record_queue_p.append(record_root_p.left) #Keep updating/recording
                    record_queue_p.append(record_root_p.right) #Keep updating/recording

            for queue_qidx in range(len_queue_q):
                record_root_q = record_queue_q.pop(0) #Record root (i.e. q)

                ##### Check if the current root tree-node existed or not #####
                if (not record_root_q):
                    record_arry_q.append(record_bound_val) #Keep updating/recording
                else:
                    record_arry_q.append(record_root_q.val) #Keep updating/recording

                    record_queue_q.append(record_root_q.left) #Keep updating/recording
                    record_queue_q.append(record_root_q.right) #Keep updating/recording

            ##### Check if the current arrays matched conditions or not #####
            if (record_arry_p != record_arry_q):
                return False

        return True
