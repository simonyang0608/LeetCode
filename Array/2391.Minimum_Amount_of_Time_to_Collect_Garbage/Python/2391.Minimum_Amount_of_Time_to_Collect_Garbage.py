class Solution(object):
    def garbageCollection(self, garbage, travel):
        """
        :type garbage: List[str]
        :type travel: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of garbage array #####
        len_garbage = len(garbage)

        ##### Record prefix-summary array #####
        record_prefix_sum = ([0] + travel)

        ##### Record garbage end-indexes #####
        record_end_idx_m, record_end_idx_p, record_end_idx_g = 0, 0, 0

        ##### Result minimun summary values #####
        res_min_sum = len(garbage[0])


        ################################################################
        #Greedy-based loop traversal with recorded prefix-summary array
        for garbage_idx in range(1, len_garbage):
            record_prefix_sum[garbage_idx] += record_prefix_sum[(garbage_idx - 1)] #Keep updating/accumulating

            ##### Check if the current indexed-char existed or not #####
            if ("M" in garbage[garbage_idx]):
                record_end_idx_m = garbage_idx #Keep updating/overwriting
            else:
                pass

            if ("P" in garbage[garbage_idx]):
                record_end_idx_p = garbage_idx #Keep updating/overwriting
            else:
                pass

            if ("G" in garbage[garbage_idx]):
                record_end_idx_g = garbage_idx #Keep updating/overwriting
            else:
                pass

            res_min_sum += len(garbage[garbage_idx]) #Keep updating/accumulating

        res_min_sum += (record_prefix_sum[record_end_idx_m] + record_prefix_sum[record_end_idx_p] + record_prefix_sum[record_end_idx_g]) #Accumulate

        return res_min_sum
