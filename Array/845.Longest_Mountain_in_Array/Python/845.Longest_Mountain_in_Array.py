class Solution(object):
    def longestMountain(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record summary (i.e. induce, reduce) #####
        record_induce_sum, record_reduce_sum = 0, 0

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        #############################
        #Greedy-based loop traversal
        while (record_trav_ptr < (len_arr - 1)):
            while (((record_trav_ptr + 1) < len_arr) and (arr[(record_trav_ptr + 1)] > arr[record_trav_ptr])):
                record_induce_sum += 1 #Keep updating/accumulating

                record_trav_ptr += 1 #Keep updating/traversing

            while (((record_trav_ptr + 1) < len_arr) and (arr[(record_trav_ptr + 1)] < arr[record_trav_ptr])):
                record_reduce_sum += 1 #Keep updating/accumulating

                record_trav_ptr += 1 #Keep updating/traversing

            ##### Check if the current summary matched conditions or not #####
            if (record_induce_sum and record_reduce_sum):
                res_max_cnter = max(res_max_cnter, ((record_induce_sum + record_reduce_sum) + 1)) #Keep updating/overwriting
            else:
                pass

            ##### Check if the current summary needs to be reset or not #####
            if (record_induce_sum):
                record_induce_sum &= 0 #Update/Reset
            else:
                pass

            if (record_reduce_sum):
                record_reduce_sum &= 0 #Update/Reset
            else:
                pass

            while (((record_trav_ptr + 1) < len_arr) and (arr[(record_trav_ptr + 1)] == arr[record_trav_ptr])):
                record_trav_ptr += 1 #Keep updating/traversing

        return res_max_cnter
