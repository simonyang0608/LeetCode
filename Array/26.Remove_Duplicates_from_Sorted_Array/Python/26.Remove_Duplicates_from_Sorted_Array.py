class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record two pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0


        ####################################
        #Two-pointers based loop traversal
        while (record_right_ptr < len_nums):
            nums[record_left_ptr] = nums[record_right_ptr] #Keep updating/recording

            next_ptr = self.binarySearch(len_nums, nums, record_right_ptr, nums[record_right_ptr]) #Next traversal pointer

            record_right_ptr = next_ptr #Keep updating/overwriting

            record_left_ptr += 1

        return record_left_ptr


    def binarySearch(self, len_nums, nums, record_idx, record_val):
        """
        :type len_nums: int
        :type nums: List[int]
        :type record_idx: int
        :type record_val: int
        :rtype: int
        """
        #========================================#
        # Binary-search based traversal function #
        #========================================#

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = (record_idx + 1), (len_nums - 1)

        ####################
        #Whole process/flow
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[record_mid_ptr] <= record_val):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return record_left_ptr
