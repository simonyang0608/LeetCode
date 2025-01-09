class Solution(object):
    def minimumSize(self, nums, maxOperations):
        """
        :type nums: List[int]
        :type maxOperations: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length, Maximun of nums array #####
        len_nums, max_nums = len(nums), max(nums)

        ##### Record pointers (i.e. middle, left, right) #####
        record_left_ptr, record_right_ptr = 1, max_nums


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            record_cnter = 0 #Record summary counter

            for nums_idx in range(len_nums):
                record_cnter += ((nums[nums_idx] - 1) // record_mid_ptr) #Keep updating/accumulating

            ##### Check if the current summary counter is smaller or not #####
            if (record_cnter <= maxOperations):
                record_right_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

            ##### Check if the current summary counter needs to be reset or not #####
            if (record_cnter):
                record_cnter &= 0 #Keep updating/reset
            else:
                pass

        return record_left_ptr
