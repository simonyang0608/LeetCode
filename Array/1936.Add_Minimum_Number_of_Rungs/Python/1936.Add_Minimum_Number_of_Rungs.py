class Solution(object):
    def addRungs(self, rungs, dist):
        """
        :type rungs: List[int]
        :type dist: int
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#
        rungs = ([0] + rungs) #Updated rungs array

        ############
        #Initialize
        ##### Length of rungs array #####
        len_rungs = len(rungs)
        len_rungs -= 1

        ##### Result minimun operations #####
        res_min_oprs = 0


        #############################
        #Greedy-based loop traversal
        for rungs_idx in range(len_rungs):
            curr_diff = (rungs[(rungs_idx + 1)] - rungs[rungs_idx]) #Current differences

            curr_times = (curr_diff // dist) #Current cycled-times
            curr_remains = (curr_diff % dist) #Current remainings

            ##### Check if the current remainings matched conditions or not #####
            if (curr_remains):
                res_min_oprs += curr_times #Keep updating/accumulating
            else:
                res_min_oprs += (curr_times - 1) #Keep updating/accumulating

        return res_min_oprs
