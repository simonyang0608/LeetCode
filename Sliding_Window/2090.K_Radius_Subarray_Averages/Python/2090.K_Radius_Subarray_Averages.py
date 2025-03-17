class Solution(object):
    def getAverages(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Total diameter #####
        total_diameter = ((2 * k) + 1)

        ##### Centered #####
        centered = k

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record summary value #####
        record_sum_val = 0

        ##### Result array #####
        res_arry = [(-1) for _ in range(len_nums)]


        #####################################
        #Sliding-window based loop traversal
        ##### Step 1: Looped-traversal for the fixed-window size #####
        if (len_nums < total_diameter): #Issue/Boundary-case handling
            return res_arry

        while (record_trav_ptr < total_diameter):
            record_sum_val += nums[record_trav_ptr] #Keep updating/accumulating

            record_trav_ptr += 1 #Keep updating/traversing

        ##### Step 2: Looped-traversal for the remainings #####
        res_arry[centered] = (record_sum_val // total_diameter) #Update/Overwrite

        centered += 1 #Update/Accumulate

        while (record_trav_ptr < len_nums):
            record_sum_val -= nums[(record_trav_ptr - total_diameter)] #Keep updating/reducing

            record_sum_val += nums[record_trav_ptr] #Keep updating/accumulating

            res_arry[centered] = (record_sum_val // total_diameter) #Keep updating/overwriting

            centered += 1 #Keep updating/accumulating

            record_trav_ptr += 1 #Keep updating/traversing

        return res_arry
