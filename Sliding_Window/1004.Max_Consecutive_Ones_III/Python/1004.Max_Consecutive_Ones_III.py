class Solution(object):
    def longestOnes(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
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

        ##### Record k-th value #####
        record_kth = 0

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        #####################################
        #Sliding-window based loop traversal
        while (record_right_ptr < len_nums):
            record_kth += (1 if (nums[record_right_ptr] == 0) else 0) #Keep updating/accumulating

            while (record_kth > k):
                record_kth -= (1 if (nums[record_left_ptr] == 0) else 0) #Keep updating/reducing

                record_left_ptr += 1 #Keep updating/traversing

            res_max_cnter = max(res_max_cnter, (record_right_ptr - record_left_ptr + 1)) #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/traversing

        return res_max_cnter
