class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record summary value #####
        record_sum_val = 0

        ##### Result maximun summary value #####
        res_max_sum = (((-1) * (10 ** 4)) - 1)


        #####################################
        #Sliding-window based loop traversal
        ##### Step 1: Looped-traversal for the fixed-window size #####
        for nums_idx in range(k):
            record_sum_val += nums[nums_idx] #Keep updating/accumulating

        ##### Step 2: Looped-traversal for the remainings #####
        res_max_sum = max(res_max_sum, ((record_sum_val / (k + 0.0)))) #Update/Overwrite

        for nums_idx in range(k, len_nums):
            record_sum_val -= nums[(nums_idx - k)] #Keep updating/reducing

            record_sum_val += nums[nums_idx] #Keep updating/accumulating

            res_max_sum = max(res_max_sum, ((record_sum_val / (k + 0.0)))) #Keep updating/overwriting

        return res_max_sum
