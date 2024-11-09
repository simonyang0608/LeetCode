class Solution(object):
    def minOperations(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
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

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record prefix-summary value #####
        record_prefix_sum = 0

        ##### Record fixed-interval value #####
        record_inter_val = (sum_nums - x)

        ##### Result maximun window-size #####
        res_max_winsize = (-1)


        #####################################
        #Sliding-window based loop traversal
        while (record_right_ptr < len_nums):
            record_prefix_sum += nums[record_right_ptr] #Keep updating/accumulating

            while ((record_left_ptr <= record_right_ptr) and (record_prefix_sum > record_inter_val)):
                record_prefix_sum -= nums[record_left_ptr] #Keep updating/reducing

                record_left_ptr += 1 #Keep updating/accumulating

            ##### Check if the current value matched conditions or not #####
            if (record_prefix_sum == record_inter_val):
                res_max_winsize = max(res_max_winsize, ((record_right_ptr - record_left_ptr) + 1)) #Keep updating/overwriting
            else:
                pass

            record_right_ptr += 1 #Keep updating/accumulating

        return ((-1) if (res_max_winsize == (-1)) else (len_nums - res_max_winsize))
