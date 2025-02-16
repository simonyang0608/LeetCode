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
        record_queue = []

        ##### Result array #####
        res_arry = []


        ##############################################################
        #Breath-first search based loop traversal with recorded queue
        record_queue.append(root) #Update/Record

        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            first_node = record_queue.pop(0) #First node

            ##### Check if the root left-half node existed or not #####
            if (first_node.left):
                record_queue.append(first_node.left) #Keep updating/recording
            else:
                pass

            ##### Check if the root right-half node existed or not #####
            if (first_node.right):
                record_queue.append(first_node.right) #Keep updating/recording
            else:
                pass

            res_arry.append(first_node) #Keep updating/recording

            for queue_idx in range((queue_size - 1)):
                record_node = record_queue.pop(0) #Record node

                (res_arry[(-1)]).next = record_node #Keep updating/overwriting

                ##### Check if the root left-half node existed or not #####
                if (record_node.left):
                    record_queue.append(record_node.left) #Keep updating/recording
                else:
                    pass

                ##### Check if the root right-half node existed or not #####
                if (record_node.right):
                    record_queue.append(record_node.right) #Keep updating/recording
                else:
                    pass

                res_arry.append(record_node) #Keep updating/recording

        return res_arry[0]
