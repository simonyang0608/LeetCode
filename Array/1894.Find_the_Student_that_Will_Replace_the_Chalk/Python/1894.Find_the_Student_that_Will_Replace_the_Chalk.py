class Solution(object):
    def chalkReplacer(self, chalk, k):
        """
        :type chalk: List[int]
        :type k: int
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length, Summary of chalk #####
        len_chalk, sum_chalk = len(chalk), sum(chalk)

        ######################################################
        #Greedy-based loop traversal with recorded remainings
        ##### Step 1: Remainings after cycled-traversal #####
        record_remains = (k % sum_chalk) #Record remainings

        ##### Step 2: Looped-traversal with recorded remainings #####
        for chalk_idx in range(len_chalk):
            record_remains -= chalk[chalk_idx] #Keep updating/reducing

            ##### Check if the current remainings matched conditions or not #####
            if (record_remains < 0):
                return chalk_idx

            else:
                pass

        return (-1)
