class Solution(object):
    def maximumSafenessFactor(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [[0 for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 399


        ############################################################################
        #Binary-search based loop traversal with recorded dynamic-programming array
        ##### Step 1: Record indexed-distance information with dynamic-programming array #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((grid[rows_idx])[cols_idx]):
                    continue
                
                (record_dp[rows_idx])[cols_idx] = 401 #Keep updating/overwriting

                ##### Check if the current rows index exceed boundary or not #####
                if ((rows_idx - 1) >= 0):
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], 
                                                          ((record_dp[(rows_idx - 1)])[cols_idx] + 1)) #Keep updating/overwriting
                else:
                    pass

                ##### Check if the current columns index exceed boundary or not #####
                if ((cols_idx - 1) >= 0):
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], 
                                                          ((record_dp[rows_idx])[(cols_idx - 1)] + 1)) #Keep updating/overwriting
                else:
                    pass

        for rows_idx in range((len_rows - 1), (-1), (-1)):
            for cols_idx in range((len_cols - 1), (-1), (-1)):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((grid[rows_idx])[cols_idx]):
                    continue

                ##### Check if the current rows index exceed boundary or not #####
                if ((rows_idx + 1) < len_rows):
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], 
                                                          ((record_dp[(rows_idx + 1)])[cols_idx] + 1)) #Keep updating/overwriting
                else:
                    pass

                ##### Check if the current columns index exceed boundary or not #####
                if ((cols_idx + 1) < len_cols):
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], 
                                                          ((record_dp[rows_idx])[(cols_idx + 1)] + 1)) #Keep updating/overwriting
                else:
                    pass

        ##### Step 2: Looped-traversal with recorded dynamic-programming array #####
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) // 2) #Record middle pointer

            record_flag = self.bfsTraversal(len_rows, len_cols, record_dp, record_mid_ptr) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (record_flag):
                record_left_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return record_left_ptr


    def bfsTraversal(self, len_rows, len_cols, record_dp, record_val):
        """
        :type len_rows: int
        :type len_cols: int
        :type record_dp: List[List[int]]
        :type record_val: int
        :rtype: bool
        """

        ############
        #Initialize
        ##### Record queue #####
        record_queue = []

        ##### Visit array #####
        visit_arry = [[False for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Directions array #####
        direc_arry = [[0, (-1)], [(-1), 0], [0, 1], [1, 0]]


        ####################
        #Whole process/flow
        ##### Check if the current indexed-value matched conditions or not #####
        if ((record_dp[0])[0] >= record_val):
            record_queue.append([0, 0]) #Update/Record

            (visit_arry[0])[0] = True #Update/Overwrite

            while (record_queue):
                queue_size = len(record_queue) #Queue-size

                for queue_idx in range(queue_size):
                    [record_rows_idx, record_cols_idx] = record_queue.pop(0) #Record rows, columns index

                    ##### Check if the current position reached target or not #####
                    if ((record_rows_idx >= (len_rows - 1)) and (record_cols_idx >= (len_cols - 1))):
                        return True

                    for direc_idx in range(4):
                        next_rows_idx, next_cols_idx = (record_rows_idx + (direc_arry[direc_idx])[0]), (record_cols_idx + (direc_arry[direc_idx])[1]) #Next rows, columns index

                        ##### Check if the next position exceed boundary or not #####
                        if (((next_rows_idx < 0) or (next_rows_idx >= len_rows)) or ((next_cols_idx < 0) or (next_cols_idx >= len_cols))):
                            continue

                        ##### Check if the next position is visited or not #####
                        if ((visit_arry[next_rows_idx])[next_cols_idx]):
                            continue

                        (visit_arry[next_rows_idx])[next_cols_idx] = True #Keep updating/overwriting

                        ##### Check if the next position-value matched conditions or not #####
                        if ((record_dp[next_rows_idx])[next_cols_idx] >= record_val):
                            record_queue.append([next_rows_idx, next_cols_idx]) #Keep updating/recording
                        else:
                            pass
        else:
            pass

        return False
