class Solution(object):
    def findPeakGrid(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[int]
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, coumns #####
        len_rows, len_cols = len(mat), len(mat[0])

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_cols - 1)

        ##### Record flags (i.e. left, right) #####
        record_lflag, record_rflag = False, False

        ##### Fixed row index #####
        fixed_row_idx = 0


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            for record_row_idx in range(len_rows):

                ##### Check if the current indexed-value is maximun or not #####
                if ((mat[record_row_idx])[record_mid_ptr] > (mat[fixed_row_idx])[record_mid_ptr]):
                    fixed_row_idx = record_row_idx #Keep updating/overwriting
                else:
                    pass

            ##### Check if the current left-half value matched conditions or not #####
            if (((record_mid_ptr - 1) < 0) or ((mat[fixed_row_idx])[(record_mid_ptr - 1)] < (mat[fixed_row_idx])[record_mid_ptr])):
                record_lflag |= True #Keep updating/overwriting
            else:
                pass

            if (((record_mid_ptr + 1) >= len_cols) or ((mat[fixed_row_idx])[(record_mid_ptr + 1)] < (mat[fixed_row_idx])[record_mid_ptr])):
                record_rflag |= True #Keep updating/overwriting
            else:
                pass

            ##### Check if the current left, right-half value matched conditions or not #####
            if (record_lflag and record_rflag):
                return [fixed_row_idx, record_mid_ptr]

            if (not record_lflag):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            
            elif (not record_rflag):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

            ##### Check if the current flag needs to be reset or not #####
            if (record_lflag):
                record_lflag &= False #Keep updating/reset
            else:
                pass

            if (record_rflag):
                record_rflag &= False #Keep updating/reset
            else:
                pass

        return [(-1), (-1)]
