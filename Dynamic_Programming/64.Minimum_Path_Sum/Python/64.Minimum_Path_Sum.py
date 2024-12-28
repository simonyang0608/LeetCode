class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [[0 for _ in range(len_cols)] for _ in range(len_rows)]

        
        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        (record_dp[0])[0] = (grid[0])[0] #Update/Overwrite

        ##### Step 1: Overwrite top-first rows, columns to matched values #####
        for cols_idx in range(1, len_cols):
            (record_dp[0])[cols_idx] = ((grid[0])[cols_idx] + (record_dp[0])[(cols_idx - 1)]) #Keep updating/overwriting

        for rows_idx in range(1, len_rows):
            (record_dp[rows_idx])[0] = ((grid[rows_idx])[0] + (record_dp[(rows_idx - 1)])[0]) #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded array #####
        for rows_idx in range(1, len_rows):
            for cols_idx in range(1, len_cols):
                (record_dp[rows_idx])[cols_idx] = ((grid[rows_idx])[cols_idx] + min((record_dp[(rows_idx - 1)])[cols_idx], (record_dp[rows_idx])[(cols_idx - 1)])) #Keep updating/overwriting

        return (record_dp[(len_rows - 1)])[(len_cols - 1)]
