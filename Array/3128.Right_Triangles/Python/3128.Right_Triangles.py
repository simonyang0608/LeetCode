class Solution(object):
    def numberOfRightTriangles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #=================================#
        # Counting-based traversal method #
        #=================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record arrays (i.e. rows, columns) #####
        record_arry_rows, record_arry_cols = [0 for _ in range(len_rows)], [0 for _ in range(len_cols)]

        ##### Result summary counter #####
        res_cnter = 0


        ####################################################
        #Counting-based loop traversal with recorded arrays
        ##### Step 1: Record indexed-values informations with arrays #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((grid[rows_idx])[cols_idx]):
                    record_arry_rows[rows_idx] += 1 #Keep updating, accumulating
                    record_arry_cols[cols_idx] += 1 #Keep updating, accumulating
                else:
                    pass

        ##### Step 2: Looped-traversal with recorded arrays #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((grid[rows_idx])[cols_idx]):

                    ##### Check if the current summary counter matched conditions or not #####
                    if (record_arry_rows[rows_idx] == 1):
                        continue

                    if (record_arry_cols[cols_idx] == 1):
                        continue

                    res_cnter += ((record_arry_rows[rows_idx] - 1) * (record_arry_cols[cols_idx] - 1)) #Keep updating, accumulating
                else:
                    pass

        return res_cnter
