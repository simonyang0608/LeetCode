class Solution(object):
    def minAbsoluteSumDiff(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of totals #####
        len_total = len(nums1)

        ##### Sorted array (i.e. nums1) #####
        sort_nums1 = sorted(nums1)

        ##### Record summary value #####
        record_sum_val = 0


        ####################################
        #Binary-search based loop traversal
        ##### Step 1: Record indexed-differences with summary value #####
        for record_idx in range(len_total):
            record_sum_val += abs((nums1[record_idx] - nums2[record_idx])) #Keep updating/accumulating

        ##### Step 2: Looped-traversal with recorded summary value #####
        res_min_sum = record_sum_val #Result minimun summary value

        for record_idx in range(len_total):
            curr_sum_val = (record_sum_val - abs((nums1[record_idx] - nums2[record_idx]))) #Current summary value

            record_min_diff = self.binarySearch(len_total, sort_nums1, nums2[record_idx]) #Record minimun difference

            curr_sum_val += record_min_diff #Keep updating/accumulating

            res_min_sum = min(res_min_sum, curr_sum_val) #Keep updating/overwriting

        return (res_min_sum % ((10 ** 9) + 7))


    def binarySearch(self, len_total, sort_nums1, record_val):
        """
        :type len_total: int
        :type sort_nums1: List[int]
        :type record_val: int
        :rtype: int
        """
        #========================================#
        # Binary-search based traversal function #
        #========================================#

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_total - 1)

        ##### Result minimun difference #####
        res_min_diff = float("inf")


        ####################
        #Whole process/flow
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            res_min_diff = min(res_min_diff, abs((sort_nums1[record_mid_ptr] - record_val))) #Result minimun difference

            ##### Check if the current indexed-value matched conditions or not #####
            if (sort_nums1[record_mid_ptr] > record_val):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        return res_min_diff
