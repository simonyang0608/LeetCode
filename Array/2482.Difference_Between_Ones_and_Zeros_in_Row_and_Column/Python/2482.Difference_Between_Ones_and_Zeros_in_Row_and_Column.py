class Solution(object):
    def onesMinusZeros(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record dictionary/hashmaps (i.e. 1th-rows, 1th-columns, 0th-rows, 0th-columns) #####
        record_dict_0rows, record_dict_0cols, record_dict_1rows, record_dict_1cols = {}, {}, {}, {}

        ##### Result array #####
        res_arry = [[0 for _ in range(len_cols)] for _ in range(len_rows)]


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Record indexed-value positions with dictionary/hashmap #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-value is 0 or 1 #####
                if ((grid[rows_idx])[cols_idx]):

                    ##### Check if the current cells position existed or not #####
                    if (rows_idx not in record_dict_1rows):
                        record_dict_1rows[rows_idx] = 1 #Keep updating/recording
                    else:
                        record_dict_1rows[rows_idx] += 1 #Keep updating/recording

                    if (cols_idx not in record_dict_1cols):
                        record_dict_1cols[cols_idx] = 1 #Keep updating/recording
                    else:
                        record_dict_1cols[cols_idx] += 1 #Keep updating/recording

                else:
                    ##### Check if the current cells position existed or not #####
                    if (rows_idx not in record_dict_0rows):
                        record_dict_0rows[rows_idx] = 1 #Keep updating/recording
                    else:
                        record_dict_0rows[rows_idx] += 1 #Keep updating/recording

                    if (cols_idx not in record_dict_0cols):
                        record_dict_0cols[cols_idx] = 1 #Keep updating/recording
                    else:
                        record_dict_0cols[cols_idx] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current cells position existed or not #####
                if (rows_idx in record_dict_1rows):
                    (res_arry[rows_idx])[cols_idx] += record_dict_1rows[rows_idx] #Keep updating/accumulating
                else:
                    pass

                if (cols_idx in record_dict_1cols):
                    (res_arry[rows_idx])[cols_idx] += record_dict_1cols[cols_idx] #Keep updating/accumulating
                else:
                    pass
                
                if (rows_idx in record_dict_0rows):
                    (res_arry[rows_idx])[cols_idx] -= record_dict_0rows[rows_idx] #Keep updating/accumulating
                else:
                    pass

                if (cols_idx in record_dict_0cols):
                    (res_arry[rows_idx])[cols_idx] -= record_dict_0cols[cols_idx] #Keep updating/accumulating
                else:
                    pass

        return res_arry
