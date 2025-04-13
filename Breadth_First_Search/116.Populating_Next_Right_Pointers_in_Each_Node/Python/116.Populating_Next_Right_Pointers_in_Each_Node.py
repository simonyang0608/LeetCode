"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution(object):
    def connect(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#
        if (not root): #Issue/Boundary-case handling
            return None

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

            record_flag = False #Record flag

            for queue_idx in range(len_queue):
                record_root = record_queue.pop(0) #Record root

                ##### Check if the current flag matched conditions or not #####
                if (not record_flag):
                    res_arry.append(record_root) #Keep updating/recording

                    record_flag |= True #Keep updating/overwriting
                else:
                    (res_arry[(-1)]).next = record_root #Keep updating/overwriting

                    res_arry.append(record_root) #Keep updating/recording

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

        return res_arry[0]
