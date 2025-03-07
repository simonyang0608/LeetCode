class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of intervals array #####
        len_intervals = len(intervals)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result summary counter #####
        res_cnter = 0


        ####################################################
        #Greedy-based loop traversal with sorted-operations
        sort_intervals = sorted(intervals, key = lambda arry: arry[1]) #Sorted-operations

        while (record_trav_ptr < len_intervals):
            first_value, second_value = (sort_intervals[record_trav_ptr])[0], (sort_intervals[record_trav_ptr])[1] #First, Second value

            while (((record_trav_ptr + 1) < len_intervals) and ((sort_intervals[(record_trav_ptr + 1)])[0] == first_value)):
                res_cnter += 1 #Keep updating/accumulating

                record_trav_ptr += 1 #Keep updating/traversing

            while (((record_trav_ptr + 1) < len_intervals) and ((sort_intervals[(record_trav_ptr + 1)])[0] < second_value)):
                res_cnter += 1 #Keep updating/accumulating

                record_trav_ptr += 1 #Keep updating/traversing

            record_trav_ptr += 1 #Keep updating/traversing

        return res_cnter
