class Solution(object):
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(matrix), len(matrix[0])

        ##### Record pointers (i.e. rows-left, right, columns-left, right) #####
        record_left_rows, record_right_rows = 0, (len_rows - 1)
        record_left_cols, record_right_cols = 0, (len_cols - 1)


        ####################################
        #Binary-search based loop traversal
        while (record_left_rows < record_right_rows):
            record_mid_rows = (record_left_rows + ((record_right_rows - record_left_rows) // 2)) #Record middle pointer (i.e. rows)

            ##### Check if the current indexed-value is larger than target or not #####
            if ((matrix[record_mid_rows])[(-1)] >= target):
                record_right_rows = record_mid_rows #Keep updating/overwriting
            else:
                record_left_rows = (record_mid_rows + 1) #Keep updating/overwriting

        while (record_left_cols <= record_right_cols):
            record_mid_cols = (record_left_cols + ((record_right_cols - record_left_cols) // 2)) #Record middle pointer (i.e. columns)

            ##### Check if the current indexed-value is larger than target or not #####
            if ((matrix[record_left_rows])[record_mid_cols] == target):
                return True

            elif ((matrix[record_left_rows])[record_mid_cols] < target):
                record_left_cols = (record_mid_cols + 1) #Keep updating/overwriting
            elif ((matrix[record_left_rows])[record_mid_cols] > target):
                record_right_cols = (record_mid_cols - 1) #Keep updating/overwriting

        return False
