class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
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

        ##### Result array #####
        res_arry = []


        #######################################################
        #Greedy-based loop traversal with sorted/updated array
        ##### Step 1: Sorted/Updated array with new interval/element #####
        intervals.append(newInterval) #Update/Record

        intervals.sort() #Sorted operations

        len_intervals += 1 #Update/Accumulate

        ##### Step 2: Looped-traversal with sorted/updated array #####
        while (record_trav_ptr < len_intervals):
            fst_val, scnd_val = (intervals[record_trav_ptr])[0], (intervals[record_trav_ptr])[1] #Firts, Second value

            while (((record_trav_ptr + 1) < len_intervals) and ((intervals[(record_trav_ptr + 1)])[0] <= scnd_val)):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((intervals[(record_trav_ptr + 1)])[1] <= scnd_val):
                    pass
                else:
                    scnd_val = (intervals[(record_trav_ptr + 1)])[1] #Keep updating/overwriting

                record_trav_ptr += 1 #Keep updating/traversing

            res_arry.append([fst_val, scnd_val]) #Keep updating/recording

            record_trav_ptr += 1 #Keep updating/traversing

        return res_arry
