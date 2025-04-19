class Solution(object):
    def minSumSquareDiff(self, nums1, nums2, k1, k2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k1: int
        :type k2: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums1)

        ##### Total of k-th value #####
        k_total = (k1 + k2)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Result summary value #####
        res_sum_val = 0


        ########################################################
        #Binary-search based loop traversal with recorded array
        ##### Step 1: Record indexed-difference with array #####
        for nums_idx in range(len_nums):
            nums1[nums_idx] = abs((nums1[nums_idx] - nums2[nums_idx])) #Keep updating/overwriting

            record_right_ptr = max(record_right_ptr, nums1[nums_idx]) #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded array #####
        nums1.sort() #Sorted-operations

        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            record_flag = self.isValid(len_nums, nums1, record_mid_ptr, k_total) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (record_flag):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        ##### Step 3: Post-process/Final completions
        if (not record_left_ptr): #Issue/Boundary-case handling
            return 0

        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums1[nums_idx] > record_left_ptr):
                k_total -= (nums1[nums_idx] - record_left_ptr) #Keep updating/reducing

                nums1[nums_idx] = record_left_ptr #Keep updating/overwriting
            else:
                pass

        if (k_total > 0):
            for nums_idx in range(len_nums):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((nums1[nums_idx] == record_left_ptr) and (k_total > 0)):
                    k_total -= 1 #Keep updating/reducing

                    nums1[nums_idx] -= 1 #Keep updating/reducing
                else:
                    pass
        else:
            pass

        for nums_idx in range(len_nums):
            res_sum_val += (nums1[nums_idx] ** 2) #Keep updating/accumulating

        return res_sum_val


    def isValid(self, len_nums, nums1, record_val, k_total):
        """
        :type len_nums: int
        :type nums1: List[int]
        :type record_val: int
        :type k_total: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Result summary value #####
        res_sum_val = 0

        ####################
        #Whole process/flow
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums1[nums_idx] > record_val):
                res_sum_val += (nums1[nums_idx] - record_val) #Keep updating/accumulating
            else:
                pass

            ##### Check if the current summary value matched conditions or not #####
            if (res_sum_val > k_total):
                return False

        return True
