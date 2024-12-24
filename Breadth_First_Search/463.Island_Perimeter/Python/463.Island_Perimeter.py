class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Breath-first-search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Result summary counter #####
        res_cnter = 0


        ##########################################
        #Breath-first-search based loop traversal
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((grid[rows_idx])[cols_idx]):
                    res_cnter += 4 #Keep updating/accumulating

                    ##### Check if the current border indexed-value matched conditions or not #####
                    if (((cols_idx - 1) >= 0) and ((grid[rows_idx])[(cols_idx - 1)])): #Left
                        res_cnter -= 1 #Keep updating/reducing
                    else:
                        pass

                    if (((rows_idx - 1) >= 0) and ((grid[(rows_idx - 1)])[cols_idx])): #Up
                        res_cnter -= 1 #Keep updating/reducing
                    else:
                        pass

                    if (((cols_idx + 1) < len_cols) and ((grid[rows_idx])[(cols_idx + 1)])): #Right
                        res_cnter -= 1 #Keep updating/reducing
                    else:
                        pass

                    if (((rows_idx + 1) < len_rows) and ((grid[(rows_idx + 1)])[cols_idx])): #Down
                        res_cnter -= 1 #Keep updating/reducing
                    else:
                        pass

                else:
                    pass

        return res_cnter
