class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#
        if (target < nums[0]): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_nums - 1)


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[record_mid_ptr] == target):
                return record_mid_ptr

            if (nums[record_mid_ptr] < target):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return record_left_ptr
