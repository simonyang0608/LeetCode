class Solution(object):
    def satisfiesConditions(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: bool
        """
        #========================================#
        # One-pass record based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Current value #####
        curr_val = (-1)


        ######################################
        #One-pass record based loop traversal
        for cols_idx in range(len_cols):
            prev_val = (grid[0])[cols_idx] #Previous value

            ##### Check if the current value matched conditions or not #####
            if (curr_val != (-1)):

                ##### Check if the current value matched conditions or not #####
                if (prev_val == curr_val):
                    return False
            else:
                pass

            for rows_idx in range(1, len_rows):

                ##### Check if the current value matched conditions or not #####
                if ((grid[rows_idx])[cols_idx] != prev_val):
                    return False

            curr_val = prev_val #Keep updating/overwriting

        return True
