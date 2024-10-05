class Solution(object):
    def minSwaps(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Summary of nums array #####
        sum_nums = sum(nums)

        ##### Record summary of sliding window #####
        record_sum_sw = sum(nums[: sum_nums])

        ##### Result maximun summary of sliding window #####
        res_max_sum_sw = record_sum_sw

        
        #####################################
        #Sliding-window based loop traversal
        for nums_idx in range(len_nums):
            record_sum_sw -= nums[nums_idx] #Keep updating/reducing
            record_sum_sw += nums[((nums_idx + sum_nums) % len_nums)] #Keep updating/accumulating

            res_max_sum_sw = max(res_max_sum_sw, record_sum_sw) #Keep updating/overwriting

        return (sum_nums - res_max_sum_sw)
