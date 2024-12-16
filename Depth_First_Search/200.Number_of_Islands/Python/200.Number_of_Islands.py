class Solution(object):
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Result summary counter #####
        res_cnter = 0


        ####################################
        #Recursion-based DFS loop traversal
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-char matched conditions or not #####
                if ((grid[rows_idx])[cols_idx] == '1'):
                    res_cnter += 1 #Keep updating/accumulating

                    self.dfsTraversal(grid, len_rows, len_cols, rows_idx, cols_idx) #Recursion function call
                else:
                    pass

        return res_cnter


    def dfsTraversal(self, grid, len_rows, len_cols, rows_idx, cols_idx):
        """
        :type grid: List[List[str]]
        :type len_rows: int
        :type len_cols: int
        :type rows_idx: int
        :type cols_idx: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (((rows_idx < 0) or (rows_idx >= len_rows)) or ((cols_idx < 0) or (cols_idx >= len_cols))): #Issue/Boundary-case handling
            return

        if ((grid[rows_idx])[cols_idx] != '1'): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        (grid[rows_idx])[cols_idx] = 'X' #Update/Overwrite

        self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1)) #Recursion function call (i.e. left)
        self.dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx) #Recursion function call (i.e. up)
        self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1)) #Recursion function call (i.e. right)
        self.dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx) #Recursion function call (i.e. down)
