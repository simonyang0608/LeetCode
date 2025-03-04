class Solution(object):
    def getLastMoment(self, n, left, right):
        """
        :type n: int
        :type left: List[int]
        :type right: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Result summary counter #####
        res_cnter = 0

        ####################################################
        #Greedy-based loop traversal with sorted-operations
        ##### Check if the current array is empty or not #####
        if (left):
            left.sort() #Sorted-operations

            res_cnter = max(res_cnter, left[(-1)]) #Update/Overwrite
        else:
            pass

        if (right):
            right.sort() #Sorted-operations

            res_cnter = max(res_cnter, (n - right[0])) #Update/Overwrite
        else:
            pass

        return res_cnter
