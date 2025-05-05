class Solution(object):
    def maximumBeauty(self, nums, k):
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

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record maximun difference #####
        record_max_diff = (k * 2)

        ##### Result maximun length #####
        res_max_length = 0


        #####################################
        #Sliding-window based loop traversal
        nums.sort() #Sorted operations

        while (record_right_ptr < len_nums):
            while ((nums[record_right_ptr] - nums[record_left_ptr]) > record_max_diff):
                record_left_ptr += 1 #Keep updating/traversing

            res_max_length = max(res_max_length, (record_right_ptr - record_left_ptr + 1)) #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/traversing

        return res_max_length
