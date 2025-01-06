class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(obstacleGrid), len(obstacleGrid[0])

        ##### Record dynamic-programming array #####
        record_dp = [[0 for _ in range(len_cols)] for _ in range(len_rows)]


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for cols_idx in range(len_cols):

            ##### Check if the current cell is valid or not #####
            if ((obstacleGrid[0])[cols_idx]):
                break
            
            (record_dp[0])[cols_idx] = 1 #Keep updating/overwriting

        for rows_idx in range(len_rows):

            ##### Check if the current cell is valid or not #####
            if ((obstacleGrid[rows_idx])[0]):
                break

            (record_dp[rows_idx])[0] = 1 #Keep updating/overwriting

        for rows_idx in range(1, len_rows):
            for cols_idx in range(1, len_cols):

                ##### Check if the current cell is valid or not #####
                if ((obstacleGrid[rows_idx])[cols_idx]):
                    continue

                (record_dp[rows_idx])[cols_idx] = ((record_dp[(rows_idx - 1)])[cols_idx] + (record_dp[rows_idx])[(cols_idx - 1)]) #Keep updating/overwriting

        return (record_dp[(len_rows - 1)])[(len_cols - 1)]
