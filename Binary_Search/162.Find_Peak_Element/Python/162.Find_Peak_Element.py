class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        if (len_nums == 1): #Issue/Boundary-case handling
            return 0

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_nums - 1)


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[record_mid_ptr] < nums[(record_mid_ptr + 1)]):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = record_mid_ptr #Keep updating/overwriting

        return record_left_ptr
