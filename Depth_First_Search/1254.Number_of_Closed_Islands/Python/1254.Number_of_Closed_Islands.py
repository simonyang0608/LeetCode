class Solution(object):
    def closedIsland(self, grid):
        """
        :type grid: List[List[int]]
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
        ##### Step 1: Looped-traversal for the edges boundary #####
        for cols_idx in range(len_cols):

            ##### Check if the current indexed-value matched conditions or not #####
            if (not (grid[0])[cols_idx]):
                self.dfsTraversal(grid, len_rows, len_cols, 0, cols_idx) #Recursion function call
            else:
                pass

            if (not (grid[(len_rows - 1)])[cols_idx]):
                self.dfsTraversal(grid, len_rows, len_cols, (len_rows - 1), cols_idx) #Recursion function call
            else:
                pass

        for rows_idx in range(1, (len_rows - 1)):

            ##### Check if the current indexed-value matched conditions or not #####
            if (not (grid[rows_idx])[0]):
                self.dfsTraversal(grid, len_rows, len_cols, rows_idx, 0) #Recursion function call
            else:
                pass

            if (not (grid[rows_idx])[(len_cols - 1)]):
                self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (len_cols - 1)) #Recursion function call
            else:
                pass

        ##### Step 2: Looped-traversal for the inner area #####
        for rows_idx in range(1, (len_rows - 1)):

            ##### Check if the current indexed-value matched conditions or not #####
            for cols_idx in range(1, (len_cols - 1)):
                if (not (grid[rows_idx])[cols_idx]):
                    res_cnter += 1 #Keep updating/accumulating

                    self.dfsTraversal(grid, len_rows, len_cols, rows_idx, cols_idx) #Recursion function call
                else:
                    pass

        return res_cnter


    def dfsTraversal(self, grid, len_rows, len_cols, rows_idx, cols_idx):
        """
        :type grid: List[List[int]]
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
        if ((grid[rows_idx])[cols_idx]): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        (grid[rows_idx])[cols_idx] = 2 #Update/Overwrite

        self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1)); #Recursion function call (i.e. left)
        self.dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx); #Recursion function call (i.e. up)
        self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1)); #Recursion function call (i.e. right)
        self.dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx); #Recursion function call (i.e. down)
