class Solution(object):
    def longestSubsequence(self, arr, difference):
        """
        :type arr: List[int]
        :type difference: int
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record dynamic-programming #####
        record_dp = {}

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        record_dp[arr[0]] = 1 #Update/Record

        for arr_idx in range(1, len_arr):

            ##### Check if the differenced-value existed or not #####
            if ((arr[arr_idx] - difference) in record_dp):
                record_dp[arr[arr_idx]] = (record_dp[(arr[arr_idx] - difference)] + 1) #Keep updating/recording
            else:
                record_dp[arr[arr_idx]] = 1 #Keep updating/recording

            res_max_cnter = max(res_max_cnter, record_dp[arr[arr_idx]]) #Keep updating/overwriting

        return res_max_cnter
