class Solution(object):
    def findMaximumLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Prefix-summary array #####
        prefix_sum = [0 for _ in range((len_nums + 1))]

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp_arry = [0 for _ in range((len_nums + 1))]

        ##### Record previous-index array #####
        record_prev_arry = [0 for _ in range((len_nums + 2))]

        ##### Previous index #####
        prev_idx = 0


        #######################################################################
        #Dynamic-programming (i.e. DP) based loop traversal with binary-search
        ##### Step 1: Record prefix-summary values with array #####
        for record_idx in range(1, (len_nums + 1)):
            prefix_sum[record_idx] = (prefix_sum[(record_idx - 1)] + nums[(record_idx - 1)]) #Keep updating/overwriting

        ##### Step 2: Looped-traversal with prefix-summary array #####
        for record_idx in range(1, (len_nums + 1)):
            prev_idx = max(prev_idx, record_prev_arry[record_idx]) #Keep updating/overwriting

            record_dp_arry[record_idx] = (record_dp_arry[prev_idx] + 1) #Keep updating/overwriting

            further_idx = self.binarySearch(len_nums, prefix_sum, prev_idx, record_idx) #Further index

            record_prev_arry[further_idx] = record_idx #Keep updating/overwriting

        return record_dp_arry[len_nums]


    def binarySearch(self, len_nums, prefix_sum, prev_idx, record_idx):
        """
        :type len_nums: int
        :type prefix_sum: List[int]
        :type prev_idx: int
        :type record_idx: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, len_nums

        ####################
        #Whole process/flow
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            record_diff = ((2 * (prefix_sum[record_idx])) - prefix_sum[prev_idx]) #Record differences

            ##### Check if the current differences matched conditions or not #####
            if (prefix_sum[record_mid_ptr] < record_diff):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return record_left_ptr
