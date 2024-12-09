class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: List[List[int]]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of intervals array #####
        len_intervals = len(intervals)

        ##### Sorted operations #####
        intervals.sort()

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record array #####
        record_arry = []

        ##### Result array #####
        res_arry = []


        #############################
        #Greedy-based loop traversal
        while (record_trav_ptr < len_intervals):
            record_arry.append((intervals[record_trav_ptr])[0]) #Keep updating/recording

            record_prev_val = (intervals[record_trav_ptr])[1] #Record previous value

            while ((record_trav_ptr + 1) < len_intervals):

                ##### Check if the current indexed-value matched conditions or not #####
                if (((intervals[(record_trav_ptr + 1)])[0] <= record_prev_val) and ((intervals[(record_trav_ptr + 1)])[1] > record_prev_val)):
                    record_prev_val = (intervals[(record_trav_ptr + 1)])[1] #Keep updating/overwriting

                elif (((intervals[(record_trav_ptr + 1)])[0] <= record_prev_val) and ((intervals[(record_trav_ptr + 1)])[1] <= record_prev_val)):
                    pass

                else:
                    break

                record_trav_ptr += 1 #Keep updating/traversing

            record_arry.append(record_prev_val) #Keep updating/recording

            res_arry.append(record_arry) #Keep updating/recording

            ##### Check if the current array needs to be reset or not #####
            if (record_arry):
                record_arry = [] #Update/Reset
            else:
                pass

            record_trav_ptr += 1 #Keep updating/traversing

        return res_arry
