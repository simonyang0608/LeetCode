class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#
        if (sum(nums) < target): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record prefix-summary value #####
        record_prefix_sum = 0

        ##### Result minimun summary counter #####
        res_min_cnter = 100001


        ###################################
        #Two-pointers based loop traversal
        while ((record_right_ptr < len_nums) and (record_left_ptr <= record_right_ptr)):
            record_prefix_sum += nums[record_right_ptr] #Keep updating/accumulating

            while (record_prefix_sum >= target):
                res_min_cnter = min(res_min_cnter, ((record_right_ptr - record_left_ptr) + 1)) #Keep updating/overwriting
                record_prefix_sum -= nums[record_left_ptr] #Keep updating/reducing

                record_left_ptr += 1 #Keep updating/accumulating

            record_right_ptr += 1 #Keep updating/accumulating

        return res_min_cnter
