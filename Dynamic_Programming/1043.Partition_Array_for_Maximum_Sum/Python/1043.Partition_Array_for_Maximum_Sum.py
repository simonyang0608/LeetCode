class Solution(object):
    def maxSumAfterPartitioning(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        if (len_arr < 2): #Issue/Boundary-ccase handling #####
            return arr[0]

        ##### Record dynamic-programming array #####
        record_dp = [0 for _ in range((len_arr + 1))]


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for record_idx in range(1, (len_arr + 1)):
            record_max_val = 0 #Record maximun value

            for sub_record_idx in range(1, (k + 1)):

                ##### Check if the current index exceed boundary or not #####
                if ((record_idx - sub_record_idx) < 0):
                    break

                record_max_val = max(record_max_val, arr[(record_idx - sub_record_idx)]) #Keep updating/overwriting

                record_dp[record_idx] = max(record_dp[record_idx], ((record_dp[(record_idx - sub_record_idx)] + (record_max_val * sub_record_idx)))) #Keep updating/overwriting

        return record_dp[len_arr]
