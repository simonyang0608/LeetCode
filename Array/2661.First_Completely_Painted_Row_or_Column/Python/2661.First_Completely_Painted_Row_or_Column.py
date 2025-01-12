class Solution(object):
    def firstCompleteIndex(self, arr, mat):
        """
        :type arr: List[int]
        :type mat: List[List[int]]
        :rtype: int
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Length of rows, columns #####
        len_rows, len_cols = len(mat), len(mat[0])

        ##### Record dictionary/hashmaps (i.e. position, rows, columns) #####
        record_dict_pos, record_dict_rows, record_dict_cols = {}, {}, {}


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Record cells position informations with dictionary/hashmap #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):
                record_dict_pos[(mat[rows_idx])[cols_idx]] = [rows_idx, cols_idx] #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for arr_idx in range(len_arr):
            record_rows_idx, record_cols_idx = (record_dict_pos[arr[arr_idx]])[0], (record_dict_pos[arr[arr_idx]])[1] #Record rows, columns

            ##### Check if the current cells position existed or not #####
            if (record_rows_idx not in record_dict_rows):
                record_dict_rows[record_rows_idx] = 1 #Keep updating/recording
            else:
                record_dict_rows[record_rows_idx] += 1 #Keep updating/recording

            if (record_cols_idx not in record_dict_cols):
                record_dict_cols[record_cols_idx] = 1 #Keep updating/recording
            else:
                record_dict_cols[record_cols_idx] += 1 #Keep updating/recording

            ##### Check if the current cells position is completed or not #####
            if ((record_dict_rows[record_rows_idx] >= len_cols) or (record_dict_cols[record_cols_idx] >= len_rows)):
                return arr_idx

        return (-1)
