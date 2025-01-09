class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        #==============================================#
        # Specific-value record based traversal method #
        #==============================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(matrix), len(matrix[0])

        ##### Zero position array #####
        zero_position_arry = []


        ################################################################
        #Specific-value record based loop traversal with recorded array
        ##### Step 1: Record zero-value position index with array #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the position-value is zero or not #####
                if (not (matrix[rows_idx])[cols_idx]):
                    zero_position_arry.append([rows_idx, cols_idx]) #Keep updating/recording
                else:
                    pass

        ##### Step 2: Looped-traversal with recorded array #####
        len_zero_position_arry = len(zero_position_arry) #Length of zero position array

        for position_idx in range(len_zero_position_arry):
            record_rows_idx, record_cols_idx = (zero_position_arry[position_idx])[0], (zero_position_arry[position_idx])[1] #Record rows, columns

            for rows_idx in range(len_rows):

                ##### Check if the position-value is zero or not #####
                if (not (matrix[rows_idx])[record_cols_idx]):
                    continue

                (matrix[rows_idx])[record_cols_idx] = 0 #Keep updating/overwriting

            for cols_idx in range(len_cols):

                ##### Check if the position-value is zero or not #####
                if (not (matrix[record_rows_idx])[cols_idx]):
                    continue

                (matrix[record_rows_idx])[cols_idx] = 0 #Keep updating/overwriting
