# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def isEvenOddTree(self, root):
        """
        :type root: Optional[TreeNode]
        :rtype: bool
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Odd flag #####
        odd_flag = True

        ##### Record queue #####
        record_queue = [root]


        ##########################################
        #Breath-first search based loop traversal
        while (record_queue):
            len_queue = len(record_queue) #Length of record queue

            record_val = (-1) #Record value

            for queue_idx in range(len_queue):
                record_root = record_queue.pop(0) #Record root

                ##### Check if the current flag matched conditions or not #####
                if (odd_flag):

                    ##### Check if the current indexed-value matched conditions or not #####
                    if (not (record_root.val % 2)):
                        return False

                    ##### Check if the current indexed-value is initialized or not #####
                    if (record_val == (-1)):
                        record_val = record_root.val #Keep updating, overwriting
                    else:
                        ##### Check if the current indexed-value matched conditions or not #####
                        if (record_root.val <= record_val):
                            return False
                        
                        record_val = record_root.val #Keep updating, overwriting
                else:
                    ##### Check if the current indexed-value matched conditions or not #####
                    if ((record_root.val % 2)):
                        return False

                    ##### Check if the current indexed-value is initialized or not #####
                    if (record_val == (-1)):
                        record_val = record_root.val #Keep updating, overwriting
                    else:
                        ##### Check if the current indexed-value matched conditions or not #####
                        if (record_root.val >= record_val):
                            return False
                        
                        record_val = record_root.val #Keep updating, overwriting

                ##### Check if the root left-half node existed or not #####
                if ((record_root.left)):
                    record_queue.append(record_root.left) #Keep updating/recording
                else:
                    pass

                ##### Check if the root right-half node existed or not #####
                if ((record_root.right)):
                    record_queue.append(record_root.right) #Keep updating/recording
                else:
                    pass

            odd_flag = (False if (odd_flag) else True) #Keep updating, overwriting

        return True
