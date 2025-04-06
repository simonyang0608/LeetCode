class Solution(object):
    def smallestDivisor(self, nums, threshold):
        """
        :type nums: List[int]
        :type threshold: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 1, max(nums)


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            record_flag = self.isLargeThreshold(len_nums, nums, record_mid_ptr, threshold) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (record_flag):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return record_left_ptr


    def isLargeThreshold(self, len_nums, nums, record_val, threshold):
        """
        :type len_nums: int
        :type nums: List[int]
        :type record_val: int
        :type threshold: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Result summary value #####
        res_sum_val = 0

        ####################
        #Whole process/flow
        for nums_idx in range(len_nums):
            record_quot, record_mod = (nums[nums_idx] // record_val), (nums[nums_idx] % record_val) #Record quotient, module

            ##### Check if the current module matched conditions or not #####
            if (record_mod):
                res_sum_val += (record_quot + 1) #Keep updating/accumulating
            else:
                res_sum_val += record_quot #Keep updating/accumulating

            if (res_sum_val > threshold):
                return True

        return False
