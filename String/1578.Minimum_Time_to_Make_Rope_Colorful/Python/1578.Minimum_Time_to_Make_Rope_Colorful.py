class Solution(object):
    def minCost(self, colors, neededTime):
        """
        :type colors: str
        :type neededTime: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of colors string #####
        len_colors = len(colors)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result summary times #####
        res_sum_times = 0


        #############################
        #Greedy-based loop traversal
        while (record_trav_ptr < len_colors):
            record_max_val = neededTime[record_trav_ptr] #Record maximun values

            while (((record_trav_ptr + 1) < len_colors) and (colors[record_trav_ptr] == colors[(record_trav_ptr + 1)])):
                next_time = neededTime[(record_trav_ptr + 1)] #Next time

                ##### Check if the current indexed-value is larger or not #####
                if (record_max_val >= next_time):
                    res_sum_times += next_time #Keep updating/accumulating

                else:
                    res_sum_times += record_max_val #Keep updating/accumulating

                    record_max_val = next_time #Keep updating/overwriting

                record_trav_ptr += 1 #Keep updating/accumulating

            record_trav_ptr += 1 #Keep updating/accumulating

        return res_sum_times
