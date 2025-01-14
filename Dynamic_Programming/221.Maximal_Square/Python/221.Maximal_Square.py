class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(matrix), len(matrix[0])

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [[0 for _ in range((len_cols + 1))] for _ in range((len_rows + 1))]

        ##### Result maximun length #####
        res_max_length = 0


        ##########################################
        #Dynamic-programming based loop traversal
        for rows_idx in range(1, (len_rows + 1)):
            for cols_idx in range(1, (len_cols + 1)):

                ##### Check if the current indexed-char matched conditions or not #####
                if (int((matrix[(rows_idx - 1)])[(cols_idx - 1)])):
                    (record_dp[rows_idx])[cols_idx] = (min((record_dp[(rows_idx - 1)])[(cols_idx - 1)], (record_dp[(rows_idx - 1)])[cols_idx], (record_dp[rows_idx])[(cols_idx - 1)]) + 1) #Keep updating/overwriting

                    res_max_length = max(res_max_length, (record_dp[rows_idx])[cols_idx]) #Keep updating/overwriting
                
                else:
                    pass

        return (res_max_length * res_max_length)
