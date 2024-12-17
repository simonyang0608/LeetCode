class Solution(object):
    def lengthOfLIS(self, nums):
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

        ##### Result array #####
        res_arry = [nums[0]]


        ####################################
        #Binary-search based loop traversal
        for nums_idx in range(1, len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[nums_idx] > res_arry[(-1)]):
                res_arry.append(nums[nums_idx]) #Keep updating/recording
            else:
                res_arry[self.binary_search(nums, res_arry, nums[nums_idx])] = nums[nums_idx] #Keep updating/overwriting

        return len(res_arry)


    def binary_search(self, nums, res_arry, record_val):
        """
        :type nums: List[int]
        :type res_arry: List[int]
        :type record_val: int
        :rtype: int
        """
        #========================================#
        # Binary-search based traversal function #
        #========================================#

        ############
        #Initialize
        ##### Record pointers (i.e. middle, left, right) #####
        record_left_ptr, record_right_ptr = 0, (len(res_arry) - 1)

        ####################
        #Whole process/flow
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if (record_val <= res_arry[record_mid_ptr]):
                record_right_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        return record_left_ptr
