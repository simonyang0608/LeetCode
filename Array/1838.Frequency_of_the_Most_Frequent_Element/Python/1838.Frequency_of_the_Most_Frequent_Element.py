class Solution(object):
    def maxFrequency(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Sorted operations #####
        nums.sort()

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record steps #####
        record_steps = 0

        ##### Result maximun summary counter (i.e. frequency) #####
        res_max_cnter = 0


        ###################################
        #Two-pointers based loop traversal
        while (record_right_ptr < len_nums):
            record_steps += nums[record_right_ptr] #Keep updating/accumulating

            while (((nums[record_right_ptr] * ((record_right_ptr - record_left_ptr) + 1)) - record_steps) > k):
                record_steps -= nums[record_left_ptr] #Keep updating/reducing

                record_left_ptr += 1 #Keep updating/accumulating

            res_max_cnter = max(res_max_cnter, ((record_right_ptr - record_left_ptr) + 1)) #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/accumulating

        return res_max_cnter
