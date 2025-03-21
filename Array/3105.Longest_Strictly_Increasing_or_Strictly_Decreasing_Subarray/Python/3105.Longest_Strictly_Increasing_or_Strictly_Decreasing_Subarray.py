class Solution(object):
    def longestMonotonicSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Result maximun window-sizes (i.e. increase, decrease) #####
        res_max_incr, res_max_decr = 0, 0


        ########################################################
        #Greedy-based loop traversal with recorded two-pointers
        ##### Step 1: Looped-traversal for the increased-subarray #####
        while (record_right_ptr < len_nums):
            while (((record_right_ptr + 1) < len_nums) and (nums[(record_right_ptr + 1)] > nums[record_right_ptr])):
                record_right_ptr += 1 #Keep updating/traversing

            res_max_incr = max(res_max_incr, (record_right_ptr - record_left_ptr + 1)) #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/traversing

            record_left_ptr = record_right_ptr #Keep updating/overwriting

        ##### Step 2: Looped-traversal for the decreased-subarray #####
        record_left_ptr &= 0 #Update/Reset
        record_right_ptr &= 0 #Update/Reset

        while (record_right_ptr < len_nums):
            while (((record_right_ptr + 1) < len_nums) and (nums[(record_right_ptr + 1)] < nums[record_right_ptr])):
                record_right_ptr += 1 #Keep updating/traversing

            res_max_decr = max(res_max_decr, (record_right_ptr - record_left_ptr + 1)) #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/traversing

            record_left_ptr = record_right_ptr #Keep updating/overwriting

        return max(res_max_incr, res_max_decr)
