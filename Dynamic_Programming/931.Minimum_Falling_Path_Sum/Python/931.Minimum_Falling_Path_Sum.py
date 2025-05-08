class Solution(object):
    def minFallingPathSum(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(matrix), len(matrix[0])

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = deepcopy(matrix)

        ##### Result minimun summary value #####
        res_min_sum = float("inf")


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for rows_idx in range((len_rows - 2), (-1), (-1)):
            for cols_idx in range(len_cols):
                next_min_val = (record_dp[(rows_idx + 1)])[cols_idx] #Next minimun value

                ##### Check if the next columns index exceed boundary or not #####
                if ((cols_idx - 1) >= 0):
                    next_min_val = min((record_dp[(rows_idx + 1)])[(cols_idx - 1)], next_min_val) #Keep updating/overwriting
                else:
                    pass

                ##### Check if the next columns index exceed boundary or not #####
                if ((cols_idx + 1) < len_cols):
                    next_min_val = min((record_dp[(rows_idx + 1)])[(cols_idx + 1)], next_min_val) #Keep updating/overwriting
                else:
                    pass

                (record_dp[rows_idx])[cols_idx] += next_min_val #Keep updating/accumulating

                ##### Check if the current rows index matched conditions or not #####
                if (not rows_idx):
                    res_min_sum = min((record_dp[rows_idx])[cols_idx], res_min_sum) #Keep updating/overwriting
                else:
                    pass

        return ((record_dp[0])[0] if (res_min_sum == float("inf")) else res_min_sum)
