class Solution(object):
    def updateMatrix(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(mat), len(mat[0])

        ##### Record dynamic-programming array #####
        record_dp = deepcopy(mat)


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        ##### Step 1: Looped-traversal for the top-down positions #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current cell position is valid or not #####
                if (not (record_dp[rows_idx])[cols_idx]):
                    continue

                (record_dp[rows_idx])[cols_idx] = ((10 ** 4) + 1) #Keep updating/overwriting

                ##### Check if the previous cell position exceed boundary or not #####
                if ((rows_idx - 1) >= 0):
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], ((record_dp[(rows_idx - 1)])[cols_idx] + 1)) #Keep updating/overwriting
                else:
                    pass

                if ((cols_idx - 1) >= 0):
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], ((record_dp[rows_idx])[(cols_idx - 1)] + 1)) #Keep updating/overwriting
                else:
                    pass
        
        ##### Step 2: Looped-traversal for the bottom-up positions #####
        for rows_idx in range((len_rows - 1), (-1), (-1)):
            for cols_idx in range((len_cols - 1), (-1), (-1)):

                ##### Check if the current cell position is valid or not #####
                if (not (record_dp[rows_idx])[cols_idx]):
                    continue

                ##### Check if the previous cell position exceed boundary or not #####
                if ((rows_idx + 1) < len_rows):
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], ((record_dp[(rows_idx + 1)])[cols_idx] + 1)) #Keep updating/overwriting
                else:
                    pass

                if ((cols_idx + 1) < len_cols):
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], ((record_dp[rows_idx])[(cols_idx + 1)] + 1)) #Keep updating/overwriting
                else:
                    pass

        return record_dp
