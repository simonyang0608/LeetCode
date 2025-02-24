class Solution(object):
    def longestSubarray(self, nums):
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

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record summary counter #####
        record_cnter = 0

        ##### Result maximun window-size #####
        res_max_winsize = 0


        ################################################################
        #Sliding-window based loop traversal with recorded two-pointers
        while (record_right_ptr < len_nums):
            record_cnter += (1 if (not nums[record_right_ptr]) else 0) #Keep updating/accumulating

            ##### Check if the current summary counter matched conditions or not #####
            if (record_cnter >= 2):
                res_max_winsize = max(res_max_winsize, (record_right_ptr - record_left_ptr - 1)) #Keep updating/overwriting

                while (record_cnter >= 2):
                    record_cnter -= (1 if (not nums[record_left_ptr]) else 0) #Keep updating/reducing

                    record_left_ptr += 1 #Keep updating/traversing
            else:
                res_max_winsize = max(res_max_winsize, (record_right_ptr - record_left_ptr)) #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/traversing

        return res_max_winsize
