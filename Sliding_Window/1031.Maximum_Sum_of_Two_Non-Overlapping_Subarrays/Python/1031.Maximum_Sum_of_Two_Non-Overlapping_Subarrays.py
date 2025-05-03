class Solution(object):
    def maxSumTwoNoOverlap(self, nums, firstLen, secondLen):
        """
        :type nums: List[int]
        :type firstLen: int
        :type secondLen: int
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        #####################################
        #Sliding-window based loop traversal
        res_sum_val1 = self.sldWindow(len_nums, nums, firstLen, secondLen) #Result summary value (i.e. 1)
        res_sum_val2 = self.sldWindow(len_nums, nums, secondLen, firstLen) #Result summary value (i.e. 2)

        return (res_sum_val1 if (res_sum_val1 > res_sum_val2) else res_sum_val2)


    def sldWindow(self, len_nums, nums, first_info, second_info):
        """
        :type len_nums: int
        :type nums: List[int]
        :type first_info: int
        :type second_info: int
        :rtype: int
        """
        #=========================================#
        # Sliding-window based traversal function #
        #=========================================#

        ############
        #Initialize
        ##### Total informations #####
        total_info = (first_info + second_info)

        ##### Record summary value (i.e. first, second) #####
        record_sum_first, record_sum_second = 0, 0

        ##### Result maximun summary value (i.e. first, total) #####
        res_max_first, res_max_total = (-1), (-1)


        ####################
        #Whole process/flow
        ##### Step 1: Looped-traversal for the fixed-window size #####
        for record_idx in range(total_info):

            ##### Check if the current index is which boundaries #####
            if (record_idx < first_info):
                record_sum_first += nums[record_idx] #Keep updating/accumulating
            else:
                record_sum_second += nums[record_idx] #Keep updating/accumulating

        ##### Step 2: Looped-traversal for the remainings #####
        res_max_first = record_sum_first #Update/Overwrite

        res_max_total = (res_max_first + record_sum_second) #Update/Overwrite

        for record_idx in range(total_info, len_nums):
            record_sum_first += (nums[(record_idx - second_info)] - nums[(record_idx - second_info - first_info)]) #Keep updating/accumulating

            res_max_first = max(record_sum_first, res_max_first) #Keep updating/overwriting

            record_sum_second += (nums[record_idx] - nums[(record_idx - second_info)]) #Keep updating/accumulating

            res_max_total = max((res_max_first + record_sum_second), res_max_total) #Keep updating/overwriting

        return res_max_total
