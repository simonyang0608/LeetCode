class Solution(object):
    def maxSideLength(self, mat, threshold):
        """
        :type mat: List[List[int]]
        :type threshold: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(mat), len(mat[0])

        ##### Minimun sider #####
        min_sider = (len_rows if (len_rows < len_cols) else len_cols)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, min_sider


        #######################################################################
        #Binary-search based loop traversal with recorded prefix-summary array
        ##### Step 1: Record prefix-summary value with array #####
        for rows_idx in range(1, len_rows):
            (mat[rows_idx])[0] += (mat[(rows_idx - 1)])[0] #Keep updating/recording

        for cols_idx in range(1, len_cols):
            (mat[0])[cols_idx] += (mat[0])[(cols_idx - 1)] #Keep updating/recording

        for rows_idx in range(1, len_rows):
            for cols_idx in range(1, len_cols):
                (mat[rows_idx])[cols_idx] += ((mat[(rows_idx - 1)])[cols_idx] + (mat[rows_idx])[(cols_idx - 1)] -
                                              (mat[(rows_idx - 1)])[(cols_idx - 1)]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded prefix-summary array #####
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) // 2) #Record middle pointer

            record_flag = self.isLargerSum(len_rows, len_cols, mat, record_mid_ptr, threshold) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (record_flag):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                record_left_ptr = record_mid_ptr #Keep updating/overwriting

        return record_left_ptr


    def isLargerSum(self, len_rows, len_cols, mat, record_val, threshold):
        """
        :type len_rows: int
        :type len_cols: int
        :type mat: List[List[int]]
        :type record_val: int
        :type threshold: int
        :rtype: bool
        """

        ####################
        #Whole process/flow
        for rows_idx in range((record_val - 1), len_rows):
            for cols_idx in range((record_val - 1), len_cols):
                record_sum_val = (mat[rows_idx])[cols_idx] #Record summary value

                ##### Check if the current rows index matched conditions or not #####
                if (rows_idx >= record_val):
                    record_sum_val -= (mat[(rows_idx - record_val)])[cols_idx] #Keep updating/reducing
                else:
                    pass

                ##### Check if the current columns index matched conditions or not #####
                if (cols_idx >= record_val):
                    record_sum_val -= (mat[rows_idx])[(cols_idx - record_val)] #Keep updating/reducing
                else:
                    pass

                ##### Check if the current rows, columns index matched conditions or not #####
                if ((rows_idx >= record_val) and (cols_idx >= record_val)):
                    record_sum_val += (mat[(rows_idx - record_val)])[(cols_idx - record_val)] #Keep updating/reducing
                else:
                    pass

                ##### Check if the current summary value matched conditions or not #####
                if (record_sum_val <= threshold):
                    return False

        return True
