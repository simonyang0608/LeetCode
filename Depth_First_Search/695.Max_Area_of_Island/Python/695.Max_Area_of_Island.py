class Solution(object):
    def maxAreaOfIsland(self, grid):
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

        ##### Record area #####
        record_area = [0]

        ##### Result maximun area #####
        res_max_area = 0


        #####################################
        #Recursion-based DFS loop traversal
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-value matched conditions or not #####
                if ((grid[rows_idx])[cols_idx] == 1):
                    self.dfsTraversal(grid, len_rows, len_cols, rows_idx, cols_idx, record_area) #Recursion function call

                    res_max_area = max(res_max_area, record_area[0]) #Keep updating/overwriting

                    record_area[0] &= 0 #Keep updating/reset
                else:
                    pass

        return res_max_area


    def dfsTraversal(self, grid, len_rows, len_cols, rows_idx, cols_idx, record_area):
        """
        :type grid: List[List[int]]
        :type len_rows: int
        :type len_cols: int
        :type rows_idx: int
        :type cols_idx: int
        :type record_area: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (((rows_idx < 0) or (rows_idx >= len_rows)) or ((cols_idx < 0) or (cols_idx >= len_cols))): #Issue/Boundary-case handling
            return

        if ((grid[rows_idx])[cols_idx] != 1): #Issue/Boundary-case handling
            return


        ####################
        #Whole process/flow
        record_area[0] += 1 #Update/Accumulate

        (grid[rows_idx])[cols_idx] = (-1) #Update/Overwrite

        self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_area) #Recursion function call (i.e. left)
        self.dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_area) #Recursion function call (i.e. up)
        self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_area) #Recursion function call (i.e. right)
        self.dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_area) #Recursion function call (i.e. down)
