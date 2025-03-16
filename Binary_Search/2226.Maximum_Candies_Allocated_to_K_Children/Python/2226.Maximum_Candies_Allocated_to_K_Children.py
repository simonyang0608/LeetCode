class Solution(object):
    def maximumCandies(self, candies, k):
        """
        :type candies: List[int]
        :type k: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length, Summary of candies array #####
        len_candies, sum_candies = len(candies), sum(candies)

        if (sum_candies < k): #Issue/Boundary-case handling
            return 0

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 1, max(candies)


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) // 2) #Record middle pointer

            record_flag = self.binarySearch(len_candies, candies, record_mid_ptr, k) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (record_flag):
                record_left_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return record_left_ptr


    def binarySearch(self, len_candies, candies, record_val, k):
        """
        :type len_candies: int
        :type candies: List[int]
        :type record_val: int
        :type k: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Result summary value #####
        res_sum_val = 0

        ####################
        #Whole process/flow
        for candies_idx in range(len_candies):
            res_sum_val += (candies[candies_idx] // record_val) #Keep updating/accumulating

            ##### Check if the current summary value is larger than k-th or not #####
            if (res_sum_val >= k):
                return True

        return False
