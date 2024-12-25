class Solution(object):
    def minOperations(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[int]
        :rtype: List[int]
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. nums, queries) #####
        len_nums, len_queries = len(nums), len(queries)

        ##### Sorted operations #####
        nums.sort()

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [0 for _ in range(len_nums + 1)]

        ##### Result array #####
        res_arry = [0 for _ in range(len_queries)]


        ######################################################################################
        #Binary-search based loop traversal with recorded dynamic-programming (i.e. DP) array
        ##### Step 1: Record prefix-summary value with dynamic-programming array #####
        for record_idx in range(1, (len_nums + 1)):
            record_dp[record_idx] = (record_dp[(record_idx - 1)] + nums[(record_idx - 1)]) #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded dynamic-programming array #####
        for queries_idx in range(len_queries):
            record_idx = self.binarySearch(nums, len_nums, queries[queries_idx]) #Record index

            res_arry[queries_idx] = (((queries[queries_idx] * record_idx) - record_dp[record_idx]) + ((record_dp[(-1)] - record_dp[record_idx]) - (queries[queries_idx] * (len_nums - record_idx)))) #Keep updating/overwriting

        return res_arry


    def binarySearch(self, nums, len_nums, record_val):
        """
        :type nums: List[int]
        :type len_nums: int
        :type record_val: int
        :rtype: int
        """
        #========================================#
        # Binary-search based traversal function #
        #========================================#

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_nums - 1)

        ####################
        #Whole process/flow
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[record_mid_ptr] < record_val):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

            elif (nums[record_mid_ptr] > record_val):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                return record_mid_ptr

        return record_left_ptr
