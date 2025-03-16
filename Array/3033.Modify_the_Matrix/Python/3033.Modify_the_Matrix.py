class Solution(object):
    def modifiedMatrix(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[List[int]]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(matrix), len(matrix[0])

        #############################
        #Greedy-based loop traversal
        for cols_idx in range(len_cols):
            record_max_val = (-2) #Record maximun value

            record_arry = [] #Record array

            for rows_idx in range(len_rows):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((matrix[rows_idx])[cols_idx] == (-1)):
                    record_arry.append(rows_idx) #Keep updating/recording

                    continue

                record_max_val = max(record_max_val, (matrix[rows_idx])[cols_idx]) #Keep updating/overwriting

            for record_val in record_arry:
                (matrix[record_val])[cols_idx] = record_max_val #Keep updating/overwriting

        return matrix
