class Solution(object):
    def subArrayRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record stack #####
        record_stack = []

        ##### Result summary value #####
        res_sum_val = 0


        ############################
        #Stack-based loop traversal
        ##### Step 1: Looped-traversal for the minimun subarray-values #####
        nums.append((((-1) * (10 ** 9)) - 1)) #Update/Record

        for nums_idx in range((len_nums + 1)):
            while (record_stack and (nums[nums_idx] < nums[record_stack[(-1)]])):
                record_idx = record_stack.pop() #Record index

                prev_idx = (record_stack[(-1)] if (record_stack) else (-1)) #Previous index

                res_sum_val -= (nums[record_idx] * (nums_idx - record_idx) * (record_idx - prev_idx)) #Keep updating/reducing

            record_stack.append(nums_idx) #Keep updating/recording

        ##### Step 2: Looped-traversal for the maximun subarray-values #####
        while (record_stack):
            record_stack.pop() #Keep updating/popped

        nums[(-1)] = ((10 ** 9) + 1) #Update/Overwrite

        for nums_idx in range((len_nums + 1)):
            while (record_stack and (nums[nums_idx] > nums[record_stack[(-1)]])):
                record_idx = record_stack.pop() #Record index

                prev_idx = (record_stack[(-1)] if (record_stack) else (-1)) #Previous index

                res_sum_val += (nums[record_idx] * (nums_idx - record_idx) * (record_idx - prev_idx)) #Keep updating/accumulating

            record_stack.append(nums_idx) #Keep updating/recording

        return res_sum_val
