class Solution(object):
    def numSubmat(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(mat), len(mat[0])

        ##### Result summary counter #####
        res_cnter = 0


        ##########################################
        #Dynamic-programming based loop traversal
        ##### Step 1: Looped-traversal for the prefix-summary counters #####
        for rows_idx in range(len_rows):
            for cols_idx in range(1, len_cols):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((mat[rows_idx])[cols_idx]):
                    (mat[rows_idx])[cols_idx] += (mat[rows_idx])[(cols_idx - 1)] #Keep updating/accumulating
                else:
                    pass

        ##### Step 2: Post-process/Final completions #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((mat[rows_idx])[cols_idx]):
                    record_cnter = (mat[rows_idx])[cols_idx] #Record summary counter

                    res_cnter += record_cnter #Keep updating/accumulating

                    for sub_rows_idx in range((rows_idx - 1), (-1), (-1)):
                        record_cnter = min(record_cnter, (mat[sub_rows_idx])[cols_idx]) #Keep updating/overwriting

                        res_cnter += record_cnter #Keep updating/accumulating
                else:
                    pass

        return res_cnter
